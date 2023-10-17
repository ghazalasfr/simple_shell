#include "main.h"

/**
 * main - Entry point
 * @ac: Number of arguments
 * @av: Array of arguments
 * Return: Always 0
 */
int main(int ac, char **av)
{
    char *line_cmd = NULL;
    char **full_cmd = NULL;
    char **path = NULL;
    struct stat st;
    int i;
    int cp = 0;

    (void)ac;
    (void)av;

    do
    {
        write(STDIN_FILENO, "$ ", 2);
        line_cmd = read_the_line_cmd();

        if (line_cmd == NULL)
        {
            free(line_cmd);
            line_cmd = NULL;
            break;
        }

        full_cmd = line_diviser(line_cmd);

        if (full_cmd != NULL)
        {
            if (stat(full_cmd[0], &st) == 0)
            {
                execute_function_cmd(full_cmd);
            }
            else if (getfullpath(full_cmd[0]))
            {
                path = getfullpath(full_cmd[0]);
                execute_function_cmd(path);
                for (i = 0; full_cmd[i] != NULL; i++)
                {
                    free(full_cmd[i]);
                    full_cmd[i] = NULL;
                }
                free(full_cmd);
                full_cmd = NULL;
            }
            else
            {
                cp = cp + 1;
                fprintf(stderr, "./hsh: %d: %s: not found\n", cp, full_cmd[0]);
                for (i = 0; full_cmd[i] != NULL; i++)
                {
                    free(full_cmd[i]);
                    full_cmd[i] = NULL;
                }
                free(full_cmd);
                full_cmd = NULL;
                exit(127);
            }
        }
    } while (1);

    return (0);
}

