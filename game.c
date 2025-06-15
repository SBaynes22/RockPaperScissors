    /*
    # File:   game.c 
    # Authors: A.Grimwood, S.Baynes
    # Date:   18/10/2024
    # Descr:  file containing game "main" program
    */
    #include "system.h" 
    #include "pio.h" 
    #include "pacer.h" 

    #include "display.h" 
    #include "navswitch.h" 
    #include "ir_uart.h"

    #include <stdbool.h> 
    #include <stdio.h>
    #include <stdint.h>

    #include "../fonts/font3x5_1.h"
    #include "tinygl.h"
    #include "messages.h"
    #include "setupmove.h"
    #include "checkresults.h"


    #define PACER_RATE 500
    #define MESSAGE_RATE 28

char opponent_choice = 'I';


    int main(void) {
        // Initialize the system, IR UART, navswitch, and TinyGL
        system_init();
        ir_uart_init();
        navswitch_init();
        tinygl_init(500); // Initialize TinyGL with a refresh rate of 1000 Hz
        tinygl_font_set(&font3x5_1); // Set the font to use
        tinygl_text_dir_set(1);
        messages("NEW GAME ");
        tinygl_clear();

        // Player selects Rock, Paper, or Scissors
        select_RPS();
        
        // Check if received opponent's choice
        check_received();
        
        // Display opponent's choice and compare
        still_messages('K', 770);
        still_messages(opponent_choice, 770);
        compare_choices();
        
        while (1) {
            // Main loop can include additional game logic or display updates
            continue ;
        }
        
        return 0;
    }


