/*  ========== H02 - Guessing Game ============
 *
 *   Student: Aidan Schrier
 *   Semester: Spring 2023
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

/*
 * Function: pick_number_in_range
 * ----------------------------------------
 *  Picks a random number between a low and high integer
 *
 *  low_value: lowest possible number
 *  high_value: highest possible number
 *
 *  returns: a randomly selected integer
 *  */
int pick_number_in_range(int low_value, int high_value){
    int random_number = rand() % high_value + low_value;
    return random_number;
}

/*
 * Function: get_user_input
 * ------------------------------
 *  asks user for an integer
 *
 *  returns: integer input by user
 *  */
int get_user_input(){
    int guessed_number;
    printf("Please enter a number between one and ten: ");
    scanf("%d", &guessed_number);
    return guessed_number;
}
/*
 * Function: offer_hint
 * ------------------------------
 *Compares two integers, and returns a message
indicating if the first integer is higher or lower
than the second.

guessed_number: the number being tested
target_number: the number being compared against

returns: a string containing a message indicating if the
guessed number was larger or smaller than the target number

*/
char* offer_hint(int guessed_number, int target_number){
    if(guessed_number > target_number){
        return "Your guess was too high.\n";
    }
    return "Your guess was too low.\n";
}
/*
 * Function: guess_number_loop:
 * ------------------------------
 *Runs a game-loop in which the user guesses a number.
When the user guesses the correct number, the loop ends.
 *
 *target_number: the number which the user is trying to guess
 *
 * Returns an integer containing the number of guesses needed.
 */
int guess_number_loop(int target_number){
    int guesses_used = 0;
    int game_is_running = 1;
    while(game_is_running == 1){
        guesses_used ++;
        int guessed_number = get_user_input();
        if(guessed_number == target_number){
            game_is_running = 0;
        }else{
            printf("%s\n",offer_hint(guessed_number, target_number));
        }
    }
    return guesses_used;
}
/*
 * Function: Guessing Game
 * ------------------------------
 *  Runs an instance of the guessing game by choosing
 *  a random number and running it into a loop in which
 *  the user tries to guess which number was chosen
 *
 *  Returns an integer containing the number of guesses needed.
 */
int guessing_game(){
    int random_number = pick_number_in_range(1, 10);
   
    int total_guesses = guess_number_loop(random_number);
    return total_guesses;
}

/** Start location for the guessing game - this must
 * remain the starting point. DO NOT reset the random seed.
 */
int start_game()
{
    printf("Welcome to my fiendishly difficult guessing game. I am the riddlemaster. You will lose!\n");
    int results [5];
    int i = 0;
    while(i < 5){
        printf("\n********************ROUND %d********************\n",i + 1);
        results[i] = guessing_game();
        printf("Wow, you got it in %d guesses!\n", results[i]);
        i ++;
    }
    printf("Thanks for playing! \nHere are your results: \n");
    i = 0;
    while(i < 5){
        printf("Round %d took you %d guesses.\n", i + 1, results[i]);
        i++;
    }
    return 0; // returns 0 if game ran validly
}

#endif
