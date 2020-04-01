#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char * argv[]){
  char * ip[3] = { "ip","address", NULL} ;
  pid_t c_pid, pid;
  int status;

  c_pid = fork();

  if (c_pid == 0){
 
    printf("Hi,Im Child :%d\n",c_pid);
    printf("Child:is executing ip\n");

                                                                                                                                                               
    execvp( ip[0], ip);
                                                                                                                                               
    perror("execve failed");
  }else if (c_pid > 0){

   printf("Hi,Im Parent :%d\n",c_pid);

    if( (pid = wait(&status)) < 0){
      perror("wait");
      _exit(1);
    }

    printf("Parent:is finish\n");

  }else{
      if(c_pid==-1){
    perror("fork failed");
    _exit(1);
  }}

  return 0; 
}
