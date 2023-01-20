/*  ========== H02 - Guessing Game ============
 *
 *   Student: UPDATE
 *   Semester: UPDATE
 *
 *   This file builds the foundation for a 'testing' framework for the game
 *   You will want to build unit tests in this file, and run them. 
 *   You have freedom to use this file as you need. It also provides
 *   an example of how to control the random seed.
 * 
 *   For reference, we are using a file similar to this for auto-grading. 
 */
#include <stdlib.h> 
#include <string.h>

#include "guessing_game.h"  

/** Test function for pick_number_in_range() **/
int test_pick_number_in_range() {
    int testvariable = pick_number_in_range(1, 10);
    int controlvariable = 4;
    if (testvariable != controlvariable){
        return 1;
    }

    return 0; // if there weren't errors
}

/** Test function for get_user_input() **/
int test_get_user_input() {
    //TODO: Figure out how to write a test function for this

    return 0; // if there weren't errors
}

/** Test function for offer_hint() **/
int test_offer_hint() {
    char* testvariable = offer_hint(1, 5);
    char* controlvariable = "Your guess was too low.\n";
    if (testvariable != controlvariable){
        return 1;
    }
    testvariable = offer_hint(1000, 5);
    controlvariable = "Your guess was too high.\n";
    if (testvariable != controlvariable){
        return 1;
    }
    return 0; // if there weren't errors
}

/** saves the random number seed out to a file,
 * so it can be regenerated for testing purposes.
 *
 * The way to save out the values would be
 * tester.out random 20 > rand_sequence.txt
 *
 * assuming tester is what you setup for your compile command of
 *  clang -Wall tests/game_tests_main.c -o tester.out
 */
void save_random(char *count_c) {
    char *end;
    long count = strtol(count_c, &end, 10);

    for(int i = 0; i < count; i++) {
       printf("%d\n", rand() % MAX_RANDOM + MIN_RANDOM);
    }

}

/* Program entry point*/
/* Options for running 

Run the unit tests: > game_tester.out  
Run the game with a set random seed: > game_tester.out play
Generate random numbers: > game_tester.out random ## 
(were ## is a number)

*/
int main(int argc, char *argv[]) {

    /**rand() generates psuedo random numbers
     * based on a seed. In production it is common
     * to use the system clock time as the seed as that
     * is always changing. however, for tests, you want
     * to fix the random numbers so you want to set the seed.
     * 
     * The problem is that different OS version + Hardware
     * still generate different random numbers even if the
     * seed is the same. A 'hacky' (but works) way to do it
     * is write a quick program that generates a series of random
     * numbers based on a specific seed. Then call your
     * other program using that specific seed. 
     * 
     * In order to conserve files, kept this as one program using
     * the program arguments to generate the random numbers. If no
     * 
    */
    srand(1); // to force the tests to have a set random number group
    if(argc > 1) {
        if(argc > 2) {
            save_random(argv[2]);
            return 1;
        }else { // assume play
            return start_game(); /* run the came for client based testing */
        }
    }else {
        int errors = 0;
        errors += test_pick_number_in_range();
        errors += test_get_user_input();
        errors += test_offer_hint();
        // add more tests here
        printf("\n**Fail %d unit tests.**\n", errors);
        return 0; 
    }
}