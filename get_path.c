#include "shell_main.h"

/**
 * getfullpath - get the full path of a command
 * @command: The command name as argument.
 *
 * Return: Return the full path.
 */
char **getfullpath(const char *command)
{
    char *path = getenv("PATH");
    char *copy = strdup(path);
    char *strtoken = strtok(copy, ":");
    char *full_cmd = NULL;
    char **result = NULL;
    char **final = NULL;
    struct stat st;
    int count = 0, i;
    (void)i;
    while (strtoken != NULL)
    {
        full_cmd = malloc(strlen(strtoken) + strlen(command) + 2);
        strcpy(full_cmd, strtoken);
        strcat(full_cmd, "/");
        strcat(full_cmd, command);
        if (stat(full_cmd, &st) == 0)
        {
            result = realloc(result, (count + 2) * sizeof(*result));
            result[count] = strdup(full_cmd);
            result[count + 1] = NULL;
            count++;
            final = result;
            free(full_cmd), full_cmd = NULL;
            free(copy), copy = NULL;
            return final;
        }
        free(full_cmd), full_cmd = NULL;
        strtoken = strtok(NULL, ":");
    }
    free(full_cmd), full_cmd = NULL;
    free(copy), copy = NULL;
    return NULL;
}

