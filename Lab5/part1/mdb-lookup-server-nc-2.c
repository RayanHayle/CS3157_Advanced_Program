/*
 * mdb-lookup-server-nc-2.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

static void die(const char *s) {
    perror(s);
    exit(1);
}
int main(int argc, char **argv) {
   
    char input[1000]; // user input size, should be enough allocated memory space
    
    printf("port number: ");
   
    while (1){
//printf("port number:");
//:fflush(stdout);    
if(fgets(input, sizeof(input), stdin) == NULL){
          break;
    }

printf("port number: ");
fflush(stdout);
      
   // printf("port number:");
        input[strcspn(input, "\n")] = '\0'; // Remove newline character from input lab 4

        pid_t pid = fork();
        
        // sscanf only excute code to create port if result is 1
        // if you have type in port number or null, or press enter 

  /* in a infite while loop, unless user presses control c
-(A) Hitting ENTER on the prompt should simply display another prompt. */   
int res = sscanf(input,"%d",&res);
       
       if(res==1){
       
        if (pid < 0) {
            die("fork failed");
        } 
        else if (pid == 0) { // Child process stays same
 //           fprintf(stderr, "[pid=%d] ", (int)getpid());
//            fprintf(stderr, "mdb-lookup-server started on port %s\n", input);
            execl("./mdb-lookup-server-nc.sh", "mdb-lookup-server-nc.sh", input, (char *)0);
            die("execl failed");
            exit(1);
        } 
        else { // Parent process
        
/* (B) It also prints out a message stating that an instance of  mdb-lookup-server has started. 
The message should include the child’s process  ID and the port number on which it’s listening. 
*/        
            printf("[pid=%d] mdb-lookup-server process started on port %s\n", (int)pid, input);
            
/*- (C) On every iteration, before it displays a prompt, it should check if any of the  child processes have terminated. 
It should display the process IDs of all  mdb-lookup-server processes that have terminated 

-(D) since the last prompt was  displayed, along with messages saying that they have terminated. 
For this,  you need to use the non-blocking version of waitpid() system call. Here is  how you use it: 
 pid = waitpid( (pid_t) -1, NULL, WNOHANG); 
*/           
 //Source: https://www.geeksforgeeks.org/exit-status-child-process-linux/
            int exit_status;
            pid_t terminated_pid = waitpid((pid_t)-1, &exit_status, 0);

            if (terminated_pid > 0) {
                printf("[pid=%d] mdb-lookup-server terminated\n", (int)terminated_pid);
            }
        }//end of parent 
    }
}//while (1) loop

}

