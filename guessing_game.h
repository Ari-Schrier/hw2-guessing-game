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

int get_user_input(){
    int guessed_number;
    printf("Please enter a number between one and ten: ");
    scanf("%d", &guessed_number);
    return guessed_number;
}

const char* offer_hint(int guessed_number, int target_number){
    if(guessed_number > target_number){
        return "Your guess was too high.\n";
    }
    return "Your guess was too low.\n";
}

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

int guessing_game(){
    int random_number = pick_number_in_range(1, 10);
    random_number = guess_number_loop(random_number);
    return random_number;
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
