#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

#define BUF_SIZE 1024

void error_read_from_file(char *filename);
void error_write_to_file(char *filename);
void error_close_fd(int fd);
int copy_files(int ac, char **av);

/**
 * error_read_from_file - prints read error message and exits
 * @filename: name of the file that cannot be read
 */
void error_read_from_file(char *filename)
{
dprintf(2, "Error: Can't read from file %s\n", filename);
exit(98);
}

/**
 * error_write_to_file - prints write error message and exits
 * @filename: name of the file that cannot be written
 */
void error_write_to_file(char *filename)
{
dprintf(2, "Error: Can't write to %s\n", filename);
exit(99);
}

/**
 * error_close_fd - prints close error message and exits
 * @fd: file descriptor that cannot be closed
 */
void error_close_fd(int fd)
{
dprintf(2, "Error: Can't close file descriptor %d\n", fd);
exit(100);
}

/**
 * copy_files - copies the content of a file to another file
 * @ac: argument count
 * @av: argument list
 *
 * Return: 0 on success, exits with error codes on failure
 */
int copy_files(int ac, char **av)
{
int fd_from, fd_to;
ssize_t octets_read, octets_written;
char buffer[BUF_SIZE];

if (ac != 3)
{
	dprintf(2, "Usage: cp file_from file_to\n");
	exit(97);
}

fd_from = open(av[1], O_RDONLY);
if (fd_from == -1)
	error_read_from_file(av[1]);
umask(0);
fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (fd_to == -1)
	error_write_to_file(av[2]);

while ((octets_read = read(fd_from, buffer, BUF_SIZE)) > 0)
{
	octets_written = write(fd_to, buffer, octets_read);
if (octets_written != octets_read)
	error_write_to_file(av[2]);
}

if (octets_read == -1)
	error_read_from_file(av[1]);

if (close(fd_from) == -1)
	error_close_fd(fd_from);

if (close(fd_to) == -1)
	error_close_fd(fd_to);

return (0);
}

/**
 * main - program entry point
 * @ac: argument count
 * @av: argument list
 *
 * Return: result of copy_files
 */
int main(int ac, char **av)
{
	return (copy_files(ac, av));
}
