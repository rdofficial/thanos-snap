/*
regular.h - Thanos Snap

The header file which declares certains constants characters and functions that are usually required by the thanos-snap.c (the main source file) to work properly. This header file needs to be imported in the thanos-snap.c file as well also in the regular.c file. This header file defines the following stuff
1. The ANSII color codes for colored output, but only for linux operating systems and not for windows.
2. The clear screen function for the linux operating system but not for windows.

The windows operating system does not defines the ANSII color codes, in other words they are not supported on there. Also, the windows compiled version would be an exe file, which would execute on double-clicking the file icon. The application would open on its separate console, thus no requirement for the clearing the console screen like what we have to do for the linux.

Author : Rishav Das
Created on : May 6, 2020

Last modified by : -
Last modified on : -
*/

// Importing the required header files
#include <stdio.h>

// DEFNINING THE ANSII COLOR CODE VARIABLES FOR COLORED OUTPUT
//
// Note :
// 1. The ANSII color code variables are only defined if the user's operating system is of linux based.
// 2. If the operating system is of windows, then the ANSII color codes are not applicable, thus we define the variables as empty strings.
#ifdef linux
// If the operating system is of linux type

#define RED "\033[91m"
#define GREEN "\033[92m"
#define YELLOW "\033[93m"
#define BLUE "\033[94m"
#define RED_REV "\033[07;91m"
#define GREEN_REV "\033[07;92m"
#define YELLOW_REV "\033[07;93m"
#define DEFCOL "\033[00m"

#elif defined(_WIN32) || defined(WIN32) || defined(_WIN64) || defined(WIN64)
// If the operating system is of windows type

#define RED ""
#define GREEN ""
#define YELLOW ""
#define BLUE ""
#define RED_REV ""
#define GREEN_REV ""
#define YELLOW_REV ""
#define DEFCOL ""
#endif

// DEFINING THE CLEAR SCREEN CODE
//
// 1. The clear screen code is only defined for the linux based operating systems and the string is left out blank if the operating system type is windows
#ifdef linux
#define CLEAR "\e[1;1H\e[2J"
#elif defined(_WIN32) || defined(WIN32) || defined(_WIN64) || defined(WIN64)
#define CLEAR ""
#endif

void clearScreen();  // The function which clears out the console screen for clear output