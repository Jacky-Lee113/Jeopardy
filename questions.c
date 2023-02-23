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

// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
	strcpy(questions[0].category, "Biology");
	strcpy(questions[0].question, "What is the largest organ on the human body?");
	strcpy(questions[0].answer, "skin");
	questions[0].value = 200;
	questions[0].answered = false;
	
	strcpy(questions[1].category, "Biology");
	strcpy(questions[1].question, "The femur (thigh bone) is stronger than concrete \n True or False?");
	strcpy(questions[1].answer, "true");
	questions[1].value = 400;
	questions[1].answered = false;
	
	strcpy(questions[2].category, "Biology");
	strcpy(questions[2].question, "The surface area of human lungs have an approximate size of what sport field/court?");
	strcpy(questions[2].answer, "tennis court");
	questions[2].value = 600;
	questions[2].answered = false;
	
	strcpy(questions[3].category, "Biology");
	strcpy(questions[3].question, "What body part enlarges 10 times it's size when stimulated?");
	strcpy(questions[3].answer, "pupil");
	questions[3].value = 800;
	questions[3].answered = false;
	
	strcpy(questions[4].category, "Punnyphrases");
	strcpy(questions[4].question, "What underwear do clouds wear?");
	strcpy(questions[4].answer, "thunderwear");
	questions[4].value = 200;
	questions[4].answered = false;
	
	strcpy(questions[5].category, "Punnyphrases");
	strcpy(questions[5].question, "What do you call a man with a rubber toe?");
	strcpy(questions[5].answer, "roberto");
	questions[5].value = 400;
	questions[5].answered = false;
	
	strcpy(questions[6].category, "Punnyphrases");
	strcpy(questions[6].question, "What is a seagull that flies over the bay?");
	strcpy(questions[6].answer, "bagel");
	questions[6].value = 600;
	questions[6].answered = false;
	
	strcpy(questions[7].category, "Punnyphrases");
	strcpy(questions[7].question, "What is a boomerang that doesn't come back?");
	strcpy(questions[7].answer, "stick");
	questions[7].value = 800;
	questions[7].answered = false;
	
	strcpy(questions[8].category, "Space");
	strcpy(questions[8].question, "What planet is closest to the sun?");
	strcpy(questions[8].answer, "mercury");
	questions[8].value = 200;
	questions[8].answered = false;
	
	strcpy(questions[9].category, "Space");
	strcpy(questions[9].question, "What is the name of the spaceship that exploded in 1986?");
	strcpy(questions[9].answer, "challenger");
	questions[9].value = 400;
	questions[9].answered = false;
	
	strcpy(questions[10].category, "Space");
	strcpy(questions[10].question, "Are meteors, meteoroids or meteorites found in space?");
	strcpy(questions[10].answer, "meteoroids");
	questions[10].value = 600;
	questions[10].answered = false;
	
	strcpy(questions[11].category, "Space");
	strcpy(questions[11].question, "The earth tilts at _____ degree angle.");
	strcpy(questions[11].answer, "23.5");
	questions[11].value = 800;
	questions[11].answered = false;
	
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
	printf("+----------------------+----------------------+----------------------+\n");
	printf("| %s              | %s         | %s                |\n", categories[0], categories[1], categories[2]);
	printf("+----------------------+----------------------+----------------------+\n");
	printf("| $%d                 | $%d                 | $%d                 |\n", questions[0].value, questions[4].value, questions[8].value);
	printf("+----------------------+----------------------+----------------------+\n");
	printf("| $%d                 | $%d                 | $%d                 |\n", questions[1].value, questions[5].value, questions[9].value);
	printf("+----------------------+----------------------+----------------------+\n");
	printf("| $%d                 | $%d                 | $%d                 |\n", questions[2].value, questions[6].value, questions[10].value);
	printf("+----------------------+----------------------+----------------------+\n");	
	printf("| $%d                 | $%d                 | $%d                 |\n", questions[3].value, questions[7].value, questions[11].value);
	printf("+----------------------+----------------------+----------------------+\n");
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
	printf("%s for $%d! Question is: ", category, value);
	for (int i = 0; i < 12; i++) {
		if (strcmp(category, questions[i].category) == 0) {
			if (value == questions[i].value) {
				printf("%s", questions[i].question);
			}
		}
	}
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    // Look into string comparison functions
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
    return false;
}