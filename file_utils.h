#ifndef FILE_UTILS_H_
#define FILE_UTILS_H_

/* read_file gets the size of a file, allocates memory
 * to a character array, and writes the file contents
 * into the array
 * 
 * @param
 * char* filename : Name of file to read from
 * char** buffer  : Character array, passed by ref,
 * 		    to read into.
 *
 * @return
 * Returns size of the file as an int
 */
int read_file(char* filename, char** buffer);

/* write_file writes a passed character array into 
 * the passed filename
 *
 * @param
 * char* filename  : Name of the file to write to
 * char *buffer	   : Character array to read from
 * 
 * @returns
 * An int to show that the file was written to 
 * sucessfully.
 */
int write_file(char* filename, char *buffer, int size);

#endif
