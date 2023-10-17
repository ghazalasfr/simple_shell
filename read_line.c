#include "shell_main.h"

/**
 * read_the_line_cmd - function that reads a line (command)
 *
 * Return: the line read
 */
char *read_the_line_cmd()
{
    char *line_cmd = NULL;
    size_t longueur = 0;
    ssize_t nb_char_read;

    nb_char_read = getline(&line_cmd, &longueur, stdin);
    if (nb_char_read == -1)
    {
        free(line_cmd);
        line_cmd = NULL;
        exit(0);
    }
    return line_cmd;
}

