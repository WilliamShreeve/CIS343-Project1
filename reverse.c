#include "file_utils.h"
#include <stdlib.h>
#include <stdio.h>

/*	Author: 	William Shreeve
 *	File:		reverse.c
 *	Project:	CIS343 Project1
 *	Class:		CIS343-02
 *	Date:		9/17/18
 */

int main(int argc, char** argv){

	//Character array to hold file contents
	char *fileCont;

	//Size of the file contents
	int sizeOfFile;

	//Check for valid amount of arguements
	if(argc != 3){
		fprintf(stderr, "Invalid arguements");
		exit(1);
	}

	sizeOfFile = read_file(argv[1], &fileCont);

	//Create array to hold reversed array using file size
	char *fileContR = (char*) malloc(sizeOfFile * sizeof(char));

	//Instantiate looping variables
	int i,j;
	j = 0;
		
	//Reverses fileCont into fileContR
	for(i = sizeOfFile-1; i >= 0; i--){
		fileContR[j] = fileCont[i];
		j++;	

	}

	//Calls write_file to write reversed array into output file
	if(write_file(argv[2], fileContR, sizeOfFile) != 0){
		fprtinf(stderr, "Error: File not written.");
	}

		
}
