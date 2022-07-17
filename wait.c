#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
 pid_t pid = fork();
 if(pid == 0){
 printf("This is child process\n");
 for (pid = 0; pid < 15; pid++) {
 printf("%d\n", pid);
 }
 }
 else{
 printf("This is parent process before wait\n");
 wait(NULL);
 printf("Parent terminating after waiting.\n");
 }
 return 0;
}
