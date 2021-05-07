/*
Thanos Snap

This application is written in C language. The application serves the feature of storage cleaning by the Thanos method i.e., half of the files will be wiped into dust (deleted) without any discrimination, in sake of making the total amount of the files to be reduced to half of what it is in the initial stage, In other words, the half of the files of the computer are deleted indiscriminately. And, finally 'EVERYTHING WILL BE BALANCED, LIKE IT SHOULD BE!'.

Author : Rishav Das (https://github.com/rdofficial/)
Created on : May 6, 2021

Last modified by : -
Last modified on : -

Authors contributed to this project (Add your name below if you have contributed) :
1. Rishav Das (github:https://github.com/rdofficial/, email:rdofficial192@gmail.com)
*/

// Importing the required header files
#include <dirent.h>
#include <string.h>
#include "regular.h"

int isFile(char *filename) {
	/* This function checks wheter a filename specified is actually a file or not, the function returns true (1) or false (0) as per the results. */

	if (strcmp(filename, ".") == 0) {
		// If the filename is for the current directory location (link), then we return false

		return 0;
	} else if (strcmp(filename, "..") == 0) {
		// If the filename is for the outside folder linking, then we return false
		
		return 0;
	} else {
		// If the filename exists, but we don't know about wheter file or directory, therefore we continue

		DIR *directory = opendir(filename);
		if (directory == NULL) {
			// If the directory fails to open, then we assume it is a file and return true

			return 1;
		} else {
			// If the directory is opened, then we return false

			return 0;
		}
	}
}

int wipeFiles(char *directoryLocation) {
	/* The function to wipe out half of the files on the current folder without any discrimination. The function takes one argument (parameter) : directoryLocation. A string which is passed to this function is the location of the directory where the function is required to be executed. The function first counts the number of files and then deletes half of them. In cases of odd number of files found in the directory, the function takes the half of one less of the total file count. Suppose there are 3 files on the specified directory, then the script deletes 1 out of the 3. The function also then lists each of the files that fall as the prey of the snap. i.e., the files which are deleted. */

	struct dirent *files;
	DIR *dir = opendir(directoryLocation);
	if (dir == NULL) {
		// If there is a failure to open the directory, then we display the error message to the user

		printf("[ Error : The requested directory cannot be opened, please check for the error ]\n");
		return 0;
	} else {
		// If the directory is opened, then we continue further

		// Listing all the files and sub-directories
		int count = 0;
		while ((files = readdir(dir)) != NULL) {
			if (isFile(files->d_name)) {
				// If the current item is a file, then we count it

				count = count + 1;
			}
		}

		// Getting the half number of the files
		printf("%s[ %d%s files to be wiped, out of %s%d%s %s]%s\n", YELLOW, (count / 2), DEFCOL, GREEN, count, DEFCOL, YELLOW, DEFCOL);
		count = count / 2;
		
		// Printing the half of the files
		dir = opendir(directoryLocation);
		while ((files = readdir(dir)) != NULL) {
			if (count == 0) {
				// If the half of the files are deleted, then we break the loop

				break;
			} else {
				// If there are still files to be deleted, then we continue

				// Checking if the current iteration is of a file or not
				if (isFile(files->d_name)) {
					// If the current iteration is of a file, then we continue

					if (remove(files->d_name) == 0) {
						// If the file is deleted, then we continue for the next file

						printf("%s[%s File wiped out : %s%s%s %s]%s\n", GREEN, DEFCOL, YELLOW, files->d_name, DEFCOL, GREEN, DEFCOL);
					} else {
						// If the file is not deleted, then we continue for the next file

						printf("%s[%s For %sreality stone%s, Thanos spared : %s%s%s %s]%s\n", RED, DEFCOL, RED, DEFCOL, YELLOW, files->d_name, DEFCOL, RED, DEFCOL);
					}
					count = count - 1;
				}
			}
		}
		closedir(dir);
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	clearScreen();

	// Printing the tool title on the screen
	printf("\t%s[ THANOS - SNAP ]%s\n\n[ %sNote%s : This tool will wipe out the half of the files a folder indiscriminately, use argument %s--help%s for help.\n\n", YELLOW_REV, DEFCOL, RED_REV, DEFCOL, YELLOW, DEFCOL);

	// Calling the wipeFiles function with passing the current directory location
	markFiles(".");

	printf("\n%s[%s The work is done, equally balanced like everything should be! %s]%s\n", GREEN, DEFCOL, GREEN, DEFCOL);
	return 0;
}