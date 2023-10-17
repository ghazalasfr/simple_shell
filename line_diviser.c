#include "shell_main.h"

/**
 * line_diviser - Function to divide a line into tokens.
 * @line: The line to be divided.
 *
 * Return: Returns an array of strings (tokens).
 */
char **line_diviser(char *line) {
    char *part;
    char *line_copy;
    char **cmd = NULL;
    int cpt_part = 0;
    
    int i = 0 ,j=0;
    const char *var = " \t\n";

    if (line==NULL) {
        free(line);
       line=NULL;
        return NULL;
    }

    line_copy = strdup(line);

    if (line_copy == NULL) {
        perror("strdup error");
        free(line_copy);
        return NULL;
    }

    part = strtok(line_copy, var);

    if (!part) {
        free(line), line= NULL;
        free(line_copy),line_copy =NULL;
        return NULL;
    }

    while (part) {
        cpt_part++;
        part = strtok(NULL, var);
    }

    free(line_copy),line_copy =NULL;
    cmd = malloc(sizeof(char *) * (cpt_part + 1));

    if (!cmd) {
        free(line);
        free(cmd);
        cmd=NULL;
        line = NULL;
        return NULL;
    }

    part = strtok(line, var);

    for (i = 0; i < cpt_part; i++) {
        cmd[i] = strdup(part);
        if (!cmd[i]) {
            perror("strdup error");
            for ( j = 0; j < i; j++) {
                free(cmd[j]);
            }
            free(cmd);
            return NULL;
        }
        part = strtok(NULL, var);
    }

    free(line), line =NULL;
    cmd[cpt_part] = NULL;
    return cmd;
    
}
