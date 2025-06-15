/*
    # File:   setupmove.c 
    # Authors: S.Baynes
    # Date:   18/10/2024
    # Descr:  module for setting up player moves
    */


#include "setupmove.h"
#include "tinygl.h"
#include "messages.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "pacer.h"



void select_RPS(void) {
    messages("  SELECT ");
    pacer_init(500); // Initialize pacer for polling frequency

    while (!has_selected) {
        // Check for navswitch events
        if (navswitch_push_event_p(NAVSWITCH_NORTH)) {
            player_choice = 'S'; // Scissors
            value = "S";
        } 
        if (navswitch_push_event_p(NAVSWITCH_EAST)) {
            player_choice = 'R'; // Rock
            value = "R";
        } else if (navswitch_push_event_p(NAVSWITCH_SOUTH)) {
            player_choice = 'P'; // Paper
            value = "P";
        }
        
        tinygl_text(value);
        
        // Confirm selection with PUSH event
        if (navswitch_push_event_p(NAVSWITCH_PUSH)) {
            has_selected = true;
            still_messages(player_choice, 770);
            send_and_receive(); // Send choice immediately
        }
        
        tinygl_update();
        navswitch_update();  // Update navswitch state
    }
}

void send_and_receive(void) {
    // Transmit player's choice
    ir_uart_init();
    ir_uart_putc(player_choice);
    if (!has_opps ) {
    // Read opponent's choice
    if (ir_uart_read_ready_p()) {
        char ch = ir_uart_getc();
        // Get the opponent's choice
        if (ch == 'P' || ch == 'S' || ch == 'R') {
            has_opps = true;
            opponent_choice = ch;
        }
    }
    }
}
