#include<stdio.h>
#include<unistd.h>
void main()
{
  fork();
  printf("using fork() system call\n");
}
