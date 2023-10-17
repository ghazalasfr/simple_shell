#include "shell_main.h"

/**
 * execute_function_cmd - Function to execute a command.
 * @cmd: The command name as argument
 *
 * Return: Returns void.
 */
void execute_function_cmd(char **cmd)
{
    pid_t childpid;
    int status;
    int i = 0;

    childpid = fork();
    switch (childpid)
    {
    case -1:
        perror("failed");
        exit(0);
    case 0:
        if (execve(cmd[0], cmd, NULL) == -1)
        {
            perror(cmd[0]);

            for (i = 0; cmd[i] != NULL; i++)
            {
                free(cmd[i]);
                cmd[i] = NULL;
            }
            free(cmd);
            cmd = NULL;
            exit(0);
        }
        break;
    default:
        wait(&status);
        for (i = 0; cmd[i] != NULL; i++)
        {
            free(cmd[i]);
            cmd[i] = NULL;
        }
        free(cmd);
        cmd = NULL;
        break;
    }
}

