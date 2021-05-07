/*
regular.c - Thanos Snap

The C source file where we define and assign the code to all the functions and variables that are declared in the regular.h header file of this project.

Author : Rishav Das
Created on : May 6, 2020

Last modified by : -
Last modified on : -
*/

// Importing the regular.h header file as all the variables, constants, and functions defined in this source file are declared in that header file
#include "regular.h"

void clearScreen() {
	/* The function to clear the console screen. This ensures clear and proper output to the user. We will print the regex in a loop to complete this task. */

	for (int i = 0; i < 100; ++i) {
		printf("%s", CLEAR);
	}
}