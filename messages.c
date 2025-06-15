/* 
# File:   Messaging file
# Authors: S.Baynes
# Date:   18/10/2024
# Descr:  To send messages to UCFK4
*/

#include "system.h"
#include "pacer.h"
#include "tinygl.h"
#include "../fonts/font3x5_1.h"
#include <string.h>
#include "messages.h"
#include <stdint.h>


#define PACER_RATE 500 
#define MESSAGE_RATE 28 

static uint32_t wait_time;
static char text_str[2];

void messages(char* text) 
//Function to create a scrolling message
{ 
    system_init(); 
    tinygl_init(PACER_RATE); 
    pacer_init(PACER_RATE); 

    tinygl_font_set(&font3x5_1); 
    tinygl_text_speed_set(MESSAGE_RATE); 
    tinygl_text_dir_set(1); // Rotate display message  
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL); 
    wait_time = 700 + (strlen(text)* 135); // calc the time it takes for full message to be displayed
    tinygl_clear() ;
    tinygl_text(text);
    while (wait_time > 0) {
        pacer_wait(); 
        tinygl_update();
        wait_time -- ;
    }
    tinygl_clear() ;
} 


void still_messages(char text, uint32_t time) 
//Function to create a stationary message for a set amount of time
{ 
    text_str[0] = text;
    system_init(); 
    tinygl_init(PACER_RATE); 
    pacer_init(PACER_RATE); 

    tinygl_font_set(&font3x5_1); 
    tinygl_text_speed_set(MESSAGE_RATE); 
    tinygl_text_dir_set(1); // Rotate display message  
    tinygl_text_mode_set(TINYGL_TEXT_MODE_STEP); 
    wait_time = time; // calc the time it takes for full message to be displayed
    tinygl_clear() ;

    tinygl_text(text_str);
    while (wait_time > 0) {
        pacer_wait(); 
        tinygl_update();
        wait_time -- ;
    }
    tinygl_clear() ;
} 
