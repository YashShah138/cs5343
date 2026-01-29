/**
 * Program: Read 10 chars from the user and write them to a new file
 * Note: Use open, read, and write
*/

#include <stdio.h> /* for printf */
#include <fcntl.h> /* for open function */
#include <unistd.h> /* for read, write, and close sys calls */
#include <stdlib.h> /* for exit */

int main(void) {
	/* Create a buffer to store the 10 chars */
	char buffer[10]; 

	/* Variable to store num of bytes currently read from stdin */
	ssize_t bytes_read;

	/* Variable to store how many bytes were actually written to the file */
	ssize_t bytes_written;

	/* File descriptor returned by open when the new file is created/opened */
	int fd;

	/* args = (x, y, z) ==> 
		x: file descriptor
		y: where the read bytes will be stored
		z: maximum number of bytes to read
	*/ 
	bytes_read = read(0, buffer, sizeof(buffer));

	if (bytes_read == -1) {
		perror("read failed");
		return EXIT_FAILURE; /* Terminate the program w/ status */
	}

	/* Open (or create) a new file named "output.txt" using the open sys call */
	/* args = (x, y, z) ==>
		x: name of file
		y: flags
			- O_WRONLY = open file w/ write only
			- O_CREAT = create the file (if does not exist)
			- O_TRUNC = if already exists, truncate to length 0
		z: mode
			- 0644 = gives read and write permissions to owner and read only to others
	*/
	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	/* Check is failed */
	if (fd == -1) {
		perror("open failed");
		return EXIT_FAILURE;
	}


	/* Write the bytes we read in */
	/* args = (x, y, z) ==>
		x: file descriptor of the opened file
		y: pointer to the data to write
		z: number of bytes we actually read from stdin
	*/
	bytes_written = write(fd, buffer, bytes_read);

	/* Check if write failed */
	if (bytes_written == -1) {
		perror("write fialed");
		close(fd);
		return EXIT_FAILURE;
	}


	/* Close file descriptor */
	if (close(fd) == -1) {
		perror("close failed");
		return EXIT_FAILURE;
	}


	printf("Successfully wrote 10 chars to output.txt\n");

	return EXIT_SUCCESS;
}
