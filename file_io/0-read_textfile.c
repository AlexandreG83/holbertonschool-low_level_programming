#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * read_textfile - reads a text file and prints it to POSIX standard output
 * @filename: name of the file to read
 * @letters: number of letters to read and print
 *
 * Return: actual number of letters read and printed,
 *         0 on failure (cannot open/read/write or filename is NULL)
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
int file_descriptor;
ssize_t read_octets, total_written = 0;
char *buffer;

if (filename == NULL)
	return (0);

file_descriptor = open(filename, O_RDONLY);
if (file_descriptor == -1)
	return (0);

buffer = malloc(sizeof(char) * (letters + 1));
if (buffer == NULL)
{
	close(file_descriptor);
	return (0);
}

read_octets = read(file_descriptor, buffer, letters);
if (read_octets == -1)
{
	free(buffer);
	close(file_descriptor);
	return (0);
}

total_written = write(STDOUT_FILENO, buffer, read_octets);
if (total_written == -1 || total_written != read_octets)
{
	free(buffer);
	close(file_descriptor);
	return (0);
}

free(buffer);
close(file_descriptor);
return (total_written);
}
