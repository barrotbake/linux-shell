#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>

#define MAXSIZE 80

// void parseSpace(char* str, char** parsed)
// {
//     int i;
  
//     for (i = 0; i < MAXSIZE; i++) {
//         parsed[i] = strsep(&str, " ");
  
//         if (parsed[i] == NULL)
//             break;
//         if (strlen(parsed[i]) == 0)
//             i--;
//     }
// }

int main(void) {
 char *args[MAXSIZE /2 + 1]; /* command line arguments */
 char *parsedArgs[MAXSIZE];
 char* parsedArgsPiped[MAXSIZE];
 int piped;

 int hasPipe;
    while (1) {
        fflush(stdout);

        char* buff;
        buff = readline("osh> ");
        char *token;
        token = strtok(buff, " ");
        int i=0;
        while(token!=NULL){
            args[i]=token;      
            token = strtok(NULL," ");
            i++;
        }
        
       
        // char* strpiped[2];
        // for (i = 0; i < 2; i++) {
        //         strpiped[i] = strsep(&args[0], "|");
        //         if (strpiped[i] == NULL)
        //             break;
        // }
        
        // if (strpiped[1] == NULL)
        //     piped = 0; 
        // else {
        //     piped = 1;
        // }
    
        // if (piped) {
        //     parseSpace(strpiped[0], parsedArgs);
        //     parseSpace(strpiped[1], parsedArgsPiped);
    
        // } else {
    
        //     parseSpace(args[0], parsedArgs);
        // }
    
        // if (strncmp(args[0], "exit",4))
        //     return 0;
        // else
        //     hasPipe = 1 + piped;
        hasPipe = 1;
        if(hasPipe == 1){
            pid_t pid = fork(); 
            // if (strncmp(args[0], "exit",4))
            //     return 0;
            if (pid == -1) {
                printf("\nFailed forking child..");
                return 0;
            } else if (pid == 0) {
                if (execvp(args[0], args) < 0) {
                    printf("\nCould not execute command..");
                }
                exit(0);
            } else {
                wait(NULL); 
            }

        }
    }
 return 0;
} 