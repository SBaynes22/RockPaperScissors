/*
    # File:   setupmove.h 
    # Authors: A.Grimwood, S.Baynes
    # Date:   18/10/2024
    # Descr:  headerfile for setupmove.c
    */


#ifndef SETUPMOVES_H
#define SETUPMOVES_H

#include <stdbool.h>

static char opponent_choice = 'I';
static bool has_opps = false;
static char* value = "G"; 
static char player_choice = 'G';
static bool has_selected = false;

void select_RPS(void);
void send_and_receive(void);

#endif
