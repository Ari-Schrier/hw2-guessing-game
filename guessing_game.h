/*  ========== H02 - Guessing Game ============
 *
 *   Student: UPDATE
 *   Semester: UPDATE
 *
 * A simple guessing game program. 
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef GUESSING_GAME_H
#define GUESSING_GAME_H

#define MAX_RANDOM 10
#define MIN_RANDOM 1

/** add as many functions as you need 
 * remember good design practices 
*/
int pick_number_in_range(int low_value, int high_value){
    int random_number = rand() % high_value + low_value;
    return random_number;
}

int guess_number_loop(int target_number){
    int guesses_used = 0;
    for 
}


/** Start location for the guessing game - this must
 * remain the starting point. DO NOT reset the random seed.
 */
int start_game()
{
    printf("Lookit me! Talking to a computer!\n");
    int random_number = pick_number_in_range(1, 10);
    printf("I rolled a %d!\n", random_number);

    return 0; // returns 0 if game ran validly
}

#endif