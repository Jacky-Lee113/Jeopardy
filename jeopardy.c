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
void tokenize(char *input, char **tokens) {
  char input_str[BUFFER_LEN];
  char *token = NULL;
  char *white_space = " \t\n\f\r\v";
  int i = 0;

  printf("%s\n", input);
  strcpy(input_str, input);
  token = strtok(input_str, white_space);

  tokens[i] = token; 

  while( token != NULL ) {
    i++;
    token = strtok(NULL, white_space);
    tokens[i] = token;
  }
}


// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players) {
  char name[300];
  printf("\033[0;33m"); 
  printf("+----------------------+------------------------+----------------------+\n");
  printf("|  ______   _____   _____   _____   _____   _____     ____    _      _ |\n");
  printf("| |______| | ____| |  _  | |  _  | |  _  | |  _  \\   |  _ \\  \\ \\    / /|\n");
  printf("|    | |   | |__   | | | | | |_| | | | | | | | |  |  | | | |  \\ \\  / / |\n");
  printf("| _  | |   |  __|  | | | | | ____| | |_| | | |_| /   | | | |   \\ \\/ /  |\n");
  printf("|| |_| |   | |___  | |_| | | |     | | | | | | | |_  | |_| |    |  |   |\n");
  printf("||_____|   |_____| |_____| |_|     |_| |_| |_| |___| |____/     |__|   |\n");
  printf("|                                                                      |\n");
  printf("+-----------------------+------FINAL SCORE------+----------------------+\n");
  printf("\033[0m");
  printf("\033[0;34m"); 

  int i, key, j;
  for (i = 1; i < num_players; i++) 
  {
    key = players[i].score;
    strcpy(name, players[i].name);
    j = i - 1;

    while (j >= 0 && players[j].score > key) 
    {
      players[j + 1].score = players[j].score;
      strcpy(players[j + 1].name, players[j].name);
      j = j - 1;
    }
    players[j + 1].score = key;
    strcpy(players[j + 1].name, name);
  }

  // display
  for(int i = num_players - 1;i >= 0;i--) {
    printf("| %-10s        %30d                     |\n", players[i].name, players[i].score);
  }
  printf("+----------------------+------------------------+----------------------+\n");

}

int main(void)
{
  // Input buffer and and commands
  char buffer[BUFFER_LEN] = { 0 };
  char **answer_tokens = calloc (100,sizeof(char*));

  /*
  char *q = "what is ontario";
  tokenize(q, answer_tokens);
  printf("%s\n", answer_tokens[2]);
  exit(0);
  */

  // Display the game introduction and initialize the questions
  initialize_game();

  printf("Welcome to Jeopardy!\n");

  int num_players;
  printf("How many players will be playing today?\n");
  scanf("%d", &num_players);

  // an array of players
  player players[num_players];

/*    
  strcpy(players[0].name, "Rui");
  strcpy(players[1].name, "Jacky");
  strcpy(players[2].name, "Nate");
  players[0].score = 600;
  players[1].score = 1200;
  players[2].score = 800;
  show_results(players, 3);
  exit(0);
  */

  // initialize each of the players in the array
  for(int i = 0; i < num_players; i++) {
    players[i].score = 0;
    printf("Please enter your name: ");
    scanf("%s", (char *) &players[i].name);
  }

  // Perform an infinite loop getting command input from users until game ends
  int answered = 0;
  while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
  {
    char *category = malloc(256 * sizeof(char *));
    char answer[BUFFER_LEN] = { 0 };
    char a[BUFFER_LEN] = { 0 };
    char b[BUFFER_LEN] = { 0 };
    int value;
    char active_player[BUFFER_LEN] = { 0 };

    // Call functions from the questions and players source files
    printf("Who's turn is it? (or quit to leave)\n");
    scanf("%s", active_player);
    if (strcmp(active_player, "quit") == 0) {
      show_results(players, num_players);
      exit(0);
    }
    if (player_exists(players, num_players, active_player) > 0)	{
      display_categories();
      printf("Please type a category (case sensitive) or quit\n");
      scanf("%s", category);
      if (strcmp(category, "quit") == 0) {
        show_results(players, num_players);
        exit(0);
      }
      printf("Please select the dollar amount (without the $ symbol)\n");
      scanf("%d", &value);
      if (already_answered(category, value) == 0)	{
        answered++;
        display_question(category, value);
        printf("\nYour answer: ");
        scanf("%s %s %s", a, b, answer);

        if (valid_answer(category, value, answer) > 0)	{
          printf("\033[0;35m");
          printf("Correct! %s has earned $%d!\n", active_player, value);
          printf("\033[0m");
          for(int i = 0; i < num_players; i++) {
            if (strcmp(active_player, players[i].name) == 0)	{
              players[i].score += value;
            }
          }
        }
      }
      else	{
        printf("\033[0;32m");
        printf("Question has already been answered, choose another question\n");
        printf("\033[0m");
      }
      if (answered == NUM_QUESTIONS) {
        show_results(players, num_players);
        exit(0);
      } else {
//        printf("answered: %d/%d\n", answered, NUM_QUESTIONS-9);
      }


    }
    else {
      printf("User is not validated, please ensure that the user exists. If user exists, ensure that name is case accurate\n");
    }
  }

}
