#include <stdio.h>
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
int create_file(const char *filename, char *text_content)
{
int file_descriptor;
ssize_t octets_written;
size_t len = 0;

if (!filename)
	return (-1);

file_descriptor = open(filename, O_WRONLY | O_CREAT
		       | O_TRUNC, S_IRUSR | S_IWUSR);
if (file_descriptor == -1)
	return (-1);

if (text_content)
{
	while (text_content[len])
		len++;
	octets_written = write(file_descriptor, text_content, len);
	if (octets_written != (ssize_t)len)
	{
		close(file_descriptor);
		return (-1);
	}
}
close(file_descriptor);
return (1);
}
