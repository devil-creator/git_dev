#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
void main()
{
 int fd1 = open("test.txt",O_RDONLY);
 if(fd1<0)
 {
   perror("Error opening\n");
   exit(1);
 }
 printf("Opened the file descriptor = %d\n",fd1);
 if(close (fd1)<0)
{
  perror("Error Closing\n");
  exit(1);
  printf("Closed the file descriptor successfully\n");
}
}
