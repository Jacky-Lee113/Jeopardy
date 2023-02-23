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
	strcpy(questions[0].question, "What is the largest organ on the human body");
	strcpy(questions[0].answer, "Skin");
	questions[0].value = 200;
	questions[0].answered = false;
	
	strcpy(questions[1].category, "Biology");
	strcpy(questions[1].question, "The femur (thigh bone) is stronger than concrete \n True or False?");
	strcpy(questions[1].answer, "True");
	questions[1].value = 400;
	questions[1].answered = false;
	strcpy(questions[2].category, "Biology");
	strcpy(questions[2].question, "What body part enlarges 10 times it's size when stimulated");
	strcpy(questions[2].answer, "Pupil");
	questions[2].value = 600;
	questions[2].answered = false;
	
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
	char v[12][20];

	for (int i = 0; i < 12; i++) {
		
		if (questions[i].answered == false) {
			
			snprintf(v[i], 20, "%d", questions[i].value);
			
		} else {

			strcpy(v[i], "   ");

		}
			
	}

	
	printf("   %s   |   %s   |   %s   \n", categories[0], categories[1], categories[2]);
	printf("  -------------------------------------------------\n");

	printf("      %s      |     %s     |         %s   \n", v[0], v[1], v[2]);
	printf("  -------------------------------------------------\n");
	
	printf("      %s      |     %s     |         %s   \n", v[3], v[4], v[5]);
	printf("  -------------------------------------------------\n");
	
	printf("      %s      |     %s     |         %s   \n", v[6], v[7], v[8]);
	printf("  -------------------------------------------------\n");

	printf("      %s      |     %s     |         %s   \n", v[9], v[10], v[11]);
	printf("  -------------------------------------------------\n");

}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
	for (int i = 0; i < 12; i++) {
		if ((questions[i].category == category) && (questions[i].value == value)) {
			printf("Question: %s (%d)\n", questions[i].question, questions[i].value);
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