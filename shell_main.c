#include "shell_main.h"

/**
 * main - Entry point
 * @ac: Number of arguments
 * @av: Array of arguments
 * Return: 0 if all good
 */
int main(int ac, char **av, char **env)
{
    char *line_cmd = NULL;
    char **full_cmd = NULL;
    char **path = NULL;
    struct stat st;
    int i;
  
    (void)ac;
    (void)av;

    do
    {
        write(STDIN_FILENO,"$ ",3);
        line_cmd = read_the_line_cmd();
        
        if (line_cmd == NULL)
        {   
            free(line_cmd);
            line_cmd=NULL;
            break; 
        }

        full_cmd = line_diviser(line_cmd);
        
        if (full_cmd != NULL)
        {    
            if (strcmp(full_cmd[0], "exit") == 0) {
             for (i = 0; full_cmd[i] != NULL; i++) {
                free(full_cmd[i]);
                full_cmd[i] =NULL;
                }
                free(full_cmd);
                full_cmd = NULL; 
            exit(0);
           }
            if (stat(full_cmd[0], &st) == 0)
            {    
            execute_function_cmd(full_cmd,env);
            
            }else {
              path = getfullpath(full_cmd[0]);
              if(path==NULL){
                fprintf(stderr, "./hsh: not found\n");
                for (i = 0; full_cmd[i] != NULL; i++) {
                free(full_cmd[i]);
                full_cmd[i] =NULL;
                }
                free(full_cmd);
                full_cmd = NULL;
              }else{
              execute_function_cmd(path,env);
             for (i = 0; full_cmd[i] != NULL; i++) {
                free(full_cmd[i]);
                full_cmd[i] =NULL;
                }
                free(full_cmd);
                full_cmd = NULL; 
              }
        } 
        }
    } while (1);

    return 0; 
}

