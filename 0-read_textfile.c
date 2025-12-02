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
ssize_t read_textfile(const char *filename, size_t letters)
{
    int file_descriptor;
    ssize_t read_octets, octets_written;
    char *buffer;

    if (!filename)
        return (0);

    file_descriptor = open(filename, O_RDONLY);
    if (file_descriptor == -1)
        return (0);

    buffer = malloc(sizeof(char) * letters);
    if (!buffer)
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

    octets_written = write(STDOUT_FILENO, buffer, read_octets);
    free(buffer);
    close(file_descriptor);

    if (octets_written != read_octets)
        return (0);

    return (octets_written);
}
