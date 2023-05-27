#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
void main()
{
  if(fork()==0)
  printf("Executing child process\n");
  else
 {
  printf("Executing parent\n");
  wait(NULL);
  printf("Executing after termination of child\n");
}
}
