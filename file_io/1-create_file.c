#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * create_file - creates a file and writes text_content to it
 * @filename: name of the file to create
 * @text_content: NULL-terminated string to write into the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
int file_descriptor, w;
size_t len = 0;

if (!filename)
	return (-1);

file_descriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
if (file_descriptor == -1)
	return (-1);

if (text_content)
{
	while (text_content[len])
		len++;
}
if (len > 0)
{
	w = write(file_descriptor, text_content, len);
	if (w == -1 || (size_t)w != len)
	{
		close(file_descriptor);
		return (-1);
	}
}
close(file_descriptor);
return (1);
}

