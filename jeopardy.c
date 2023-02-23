/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players);


int main(void)
{
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();

    printf("Welcome to Jeopardy!\n");
    
    int num_players;
    printf("How many players will be playing today?\n");
    scanf("%d", &num_players);
    
    // an array of players
    player players[num_players];
    
    // initialize each of the players in the array
	for(int i = 0; i < num_players; i++) {
        players[i].score = 0;
		printf("Please enter your name: ");
        scanf("%s", (char *) &players[i].name);
    }

    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
		char *category;
		int value;
        // Call functions from the questions and players source files
		display_categories();
		printf("Please type a category (case sensitive)\n");
		scanf("%s", category);
		printf("You have selected %s!\n", category);
		printf("Please select the dollar amount (without the $ symbol)\n");
		scanf("%d", value);
		display_question(category, value);
        // Execute the game until all questions are answered

        // Display the final results and exit
    }
	
}
