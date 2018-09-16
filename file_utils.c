#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

/*	Author:		William Shreeve
 *	File:		file_utils.c
 *	Project:	CIS343 Project1
 *	Class:		CIS343-02
 *	Date:		9/17/2018
 */

/* read_file takes in two parameters to read
 * from a file, allocate memory to a passed
 * character array, and reads the file contents
 * into the array, returning the size of the array.
 */

int read_file(char* filename, char **buffer){

	//CODE GIVEN BY PROFESSOR WOODRING
	//Gets size of file named filename
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;

	//File pointer
	FILE *fp;

	//Opens file for read, checks for valid file
	if((fp = fopen(filename, "r")) == NULL){
		fprintf(stderr, "Invalid file name");
		exit(1);
	}
	
	//Allocate memory for array to hold contents
	*buffer =  malloc(size * sizeof(char));
	
	//For loop to read in all characters
	int i;
       	for(i = 0; i < size; i++){
		(*buffer)[i] =  fgetc(fp);

	}	

	//Closes file
	fclose(fp);

	//Return size of file to be used later
	return size;
}

/* write_file takes in three parameters to write a
 * array of characters into a file
 */

int write_file(char* filename, char *buffer, int size){

	//Declare file pointer
	FILE *fp;

	//Opens file for write, checks for valid file
	if((fp = fopen(filename, "w")) == NULL){
		fprintf(stderr, "Invlaid file name");
		exit(1);
	}

	//For loop to write array to file
	int i;
	for(i = 0; i < size; i++){
		fputc(buffer[i], fp);
	}
	
	//Closes file
	fclose(fp);
	
	return 1;
}
