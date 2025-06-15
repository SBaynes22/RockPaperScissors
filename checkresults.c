/*
    # File:   checkresults.c 
    # Authors: S.Baynes
    # Date:   18/10/2024
    # Descr:  module for comparing player moves
    */


#include "checkresults.h"
#include "messages.h"
#include "setupmove.h"
#include <stdbool.h>



// Function to check if opponent has received the selection
void check_received(void) {
    // Wait until a character is available to read
    while (!has_opps) {
        still_messages('W', 100);
        send_and_receive();
    }
}



// Compare choices
void compare_choices(void) {
    messages("COMPARING");

    if (player_choice == opponent_choice) {
        messages("  TIE! ");
    } else if ((player_choice == 'R' && opponent_choice == 'S') ||
               (player_choice == 'S' && opponent_choice == 'P') ||
               (player_choice == 'P' && opponent_choice == 'R')) {
        messages(" YOU WIN! ");
    } else {
        messages(" YOU LOSE! ");
    }
}
