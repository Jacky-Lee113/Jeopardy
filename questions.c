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
#include "questions.h"

char buffer[4] = "";


// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
	strcpy(questions[0].category, "Biology");
	strcpy(questions[0].question, "What is the largest organ on the human body?");
	strcpy(questions[0].answer, "skin");
	strcpy(questions[0].buffer, "200");
	questions[0].value = 200;
	questions[0].answered = false;
	
	strcpy(questions[1].category, "Biology");
	strcpy(questions[1].question, "The femur (thigh bone) is stronger than concrete \nTrue or False?");
	strcpy(questions[1].answer, "true");
	strcpy(questions[1].buffer, "400");
	questions[1].value = 400;
	questions[1].answered = false;
	
	strcpy(questions[2].category, "Biology");
	strcpy(questions[2].question, "The surface area of human lungs have an approximate size of what sport field/court? Hint: answer with the sport only");
	strcpy(questions[2].answer, "tennis");
	strcpy(questions[2].buffer, "600");
	questions[2].value = 600;
	questions[2].answered = false;
	
	strcpy(questions[3].category, "Biology");
	strcpy(questions[3].question, "What body part enlarges 10 times it's size when stimulated?");
	strcpy(questions[3].answer, "pupil");
	strcpy(questions[3].buffer, "800");
	questions[3].value = 800;
	questions[3].answered = false;
	
	strcpy(questions[4].category, "Punnyphrases");
	strcpy(questions[4].question, "What underwear do clouds wear?");
	strcpy(questions[4].answer, "thunderwear");
	strcpy(questions[4].buffer, "200");
	questions[4].value = 200;
	questions[4].answered = false;
	
	strcpy(questions[5].category, "Punnyphrases");
	strcpy(questions[5].question, "What do you call a man with a rubber toe?");
	strcpy(questions[5].answer, "roberto");
	strcpy(questions[5].buffer, "400");
	questions[5].value = 400;
	questions[5].answered = false;
	
	strcpy(questions[6].category, "Punnyphrases");
	strcpy(questions[6].question, "What is a seagull that flies over the bay?");
	strcpy(questions[6].answer, "bagel");
	strcpy(questions[6].buffer, "600");
	questions[6].value = 600;
	questions[6].answered = false;
	
	strcpy(questions[7].category, "Punnyphrases");
	strcpy(questions[7].question, "What is a boomerang that doesn't come back?");
	strcpy(questions[7].answer, "stick");
	strcpy(questions[7].buffer, "800");
	questions[7].value = 800;
	questions[7].answered = false;
	
	strcpy(questions[8].category, "Space");
	strcpy(questions[8].question, "What planet is closest to the sun?");
	strcpy(questions[8].answer, "mercury");
	strcpy(questions[8].buffer, "200");
	questions[8].value = 200;
	questions[8].answered = false;
	
	strcpy(questions[9].category, "Space");
	strcpy(questions[9].question, "What is the name of the spaceship that exploded in 1986?");
	strcpy(questions[9].answer, "challenger");
	strcpy(questions[9].buffer, "400");
	questions[9].value = 400;
	questions[9].answered = false;
	
	strcpy(questions[10].category, "Space");
	strcpy(questions[10].question, "Are meteors, meteoroids or meteorites found in space?");
	strcpy(questions[10].answer, "meteoroids");
	strcpy(questions[10].buffer, "600");
	questions[10].value = 600;
	questions[10].answered = false;
	
	strcpy(questions[11].category, "Space");
	strcpy(questions[11].question, "The earth tilts at _____ degree angle.");
	strcpy(questions[11].answer, "23.5");
	strcpy(questions[11].buffer, "800");
	questions[11].value = 800;
	questions[11].answered = false;
	
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
	printf("\033[0;33m"); 
	printf("+----------------------+------------------------+----------------------+\n");
	printf("|  ______   _____   _____   _____   _____   _____     ____    _      _ |\n");
	printf("| |______| | ____| |  _  | |  _  | |  _  | |  _  \\   |  _ \\  \\ \\    / /|\n");
	printf("|    | |   | |__   | | | | | |_| | | | | | | | |  |  | | | |  \\ \\  / / |\n");
	printf("| _  | |   |  __|  | | | | | ____| | |_| | | |_| /   | | | |   \\ \\/ /  |\n");
	printf("|| |_| |   | |___  | |_| | | |     | | | | | | | |_  | |_| |    |  |   |\n");
	printf("||_____|   |_____| |_____| |_|     |_| |_| |_| |___| |____/     |__|   |\n");
	printf("|                                                                      |\n");
	printf("+-----------------------+-----------------------+----------------------+\n");
	printf("\033[0m");
	printf("\033[0;34m"); 
	printf("+-----------------------+-----------------------+----------------------+\n");
	printf("| %s               | %s          | %s                |\n", categories[0], categories[1], categories[2]);
	printf("+-----------------------+-----------------------+----------------------+\n");
	printf("| $%s                  | $%s                  | $%s                 |\n", questions[0].buffer, questions[4].buffer, questions[8].buffer);
	printf("+-----------------------+-----------------------+----------------------+\n");
	printf("| $%s                  | $%s                  | $%s                 |\n", questions[1].buffer, questions[5].buffer, questions[9].buffer);
	printf("+-----------------------+-----------------------+----------------------+\n");
	printf("| $%s                  | $%s                  | $%s                 |\n", questions[2].buffer, questions[6].buffer, questions[10].buffer);
	printf("+-----------------------+-----------------------+----------------------+\n");	
	printf("| $%s                  | $%s                  | $%s                 |\n", questions[3].buffer, questions[7].buffer, questions[11].buffer);
	printf("+-----------------------+-----------------------+----------------------+\n");
	printf("\033[0m");
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
	printf("%s for $%d! Question is: ", category, value);
	for (int i = 0; i < 12; i++) {
		if (strcmp(category, questions[i].category) == 0) {
			if (value == questions[i].value) {
				printf("\033[0;31m"); 
				printf("%s", questions[i].question);
				printf("\033[0m");
			}
		}
	}
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    // Look into string comparison functions
	for (int i = 0; i < 12; i++) {
		if (strcmp(category, questions[i].category) == 0) {
			if (value == questions[i].value) {
				if(strcmp(questions[i].answer, answer) == 0)	{
					strcpy(questions[i].buffer, "0  ");
					questions[i].answered = true;
					return true;
				}
				else	{
				printf("Nice try! Correct answer is: %s\n", questions[i].answer);
				strcpy(questions[i].buffer, "0  ");
				questions[i].answered = true;
				}
			}
		}
	}
	return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
	for (int i = 0; i < 12; i++) {
		if (strcmp(category, questions[i].category) == 0) {
			if (value == questions[i].value) {
				if (questions[i].answered == true) {
					return true;
				}
			}
		}
	}
    return false;
}