#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

#define BUF_SIZE 1024

void error_read_from_file(void);
void no_close_file_descriptor_to(void);
void no_close_file_descriptor_from(void);
int copy_files(int ac, char **av);

/**
 * error_read_from_file - prints read error and exits
 */
void error_read_from_file(void)
{
	dprintf(2, "Error: Can't read from file %s\n", av[1]);
	exit(98);
}

/**
 * no_close_file_descriptor_to - prints close
 * error for fd_to and exits
 */
void no_close_file_descriptor_to(void)
{
	dprintf(2, "Error: Can't close file
descriptor %d\n", file_descriptor_to);
	exit(100);
}

/**
 * no_close_file_descriptor_from - prints close
 * error for fd_from and exits
 */
void no_close_file_descriptor_from(void)
{
	dprintf(2, "Error: Can't close file descriptor %d\n",
file_descriptor_from);
	exit(100);
}

/**
 * main - copies the content of a file to another file
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success, exits with error codes on failure
 */
int main
{
	return (copy_files(ac, av));
}

 
int copy_files(int ac, char **av)
{
int file_descriptor_from, file_descriptor_to;
ssize_t octets_read, octets_written;
char buffer[BUF_SIZE];

if (ac != 3)
{
	dprintf(2, "Usage: cp file_from file_to\n");
	exit(97);
}

file_descriptor_from = open(av[1], O_RDONLY);
if (file_descriptor_from == -1)
	error_read_from_file();

file_descriptor_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (file_descriptor_from == -1)
{
	dprintf(2, "Error: Can't write to %s\n", av[2]);
	if (close(file_descriptor_from) == -1)
		dprintf(2, "Error: Can't close file descriptor %d\n",
file_descriptor_from);
	exit(99);
}

while ((octets_read = read(file_descriptor_from, buffer, BUF_SIZE)) > 0)
{
	octets_written = write(file_descriptor_to, buffer, octets_read);
	if (octets_written != octets_read)
	{
		dprintf(2, "Error: Can't write to %s\n", av[2]);
		if (close(file_descriptor_from) == -1)
			dprintf(2, "Error: Can't close file descriptor %d\n",
file_descriptor_from);
	if (close(file_descriptor_to) == -1)
		dprintf(2, "Error: Can't close file descriptor %d\n", file_descriptor_to);
	exit(99);
	}
}

if (octets_read == -1)
{
	dprintf(2, "Error: Can't read from file %s\n", av[1]);
	if (close(file_descriptor_from) == -1)
		dprintf(2, "Error: Can't close file descriptor %d\n",
file_descriptor_from);
	if (close(file_descriptor_to) == -1)
		dprintf(2, "Error: Can't close file descriptor %d\n",
file_descriptor_to);
	exit(98);
}

if (close(file_descriptor_from) == -1)
	no_close_file_descriptor_from();
if (close(file_descriptor_to) == -1)
	no_close_file_descriptor_to();
return (0);
}
