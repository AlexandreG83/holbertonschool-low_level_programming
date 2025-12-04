#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

/**
 * error_exit - prints an error message and exits
 * @code: exit code
 * @msg: error message format string
 * @arg: argument to include in message
 */
void error_exit(int code, const char *msg, const char *arg)
{
    dprintf(STDERR_FILENO, msg, arg);
    exit(code);
}

/**
 * safe_close - closes a file descriptor, exits if failure
 * @fd: file descriptor to close
 */
void safe_close(int fd)
{
    if (close(fd) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
        exit(100);
    }
}

/**
 * main - copies the content of a file to another file
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, exits with appropriate error code on failure
 */
int main(int argc, char *argv[])
{
    int fd_from, fd_to;
    ssize_t bytes_read, bytes_written;
    char buffer[BUF_SIZE];

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
        error_exit(98, "Error: Can't read from file %s\n", argv[1]);

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1)
    {
        safe_close(fd_from);
        error_exit(99, "Error: Can't write to %s\n", argv[2]);
    }

    while ((bytes_read = read(fd_from, buffer, BUF_SIZE)) > 0)
    {
        bytes_written = write(fd_to, buffer, bytes_read);
        if (bytes_written != bytes_read)
        {
            safe_close(fd_from);
            safe_close(fd_to);
            error_exit(99, "Error: Can't write to %s\n", argv[2]);
        }
    }

    if (bytes_read == -1)
    {
        safe_close(fd_from);
        safe_close(fd_to);
        error_exit(98, "Error: Can't read from file %s\n", argv[1]);
    }

    safe_close(fd_from);
    safe_close(fd_to);

    return (0);
}
