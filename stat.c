#include<stdio.h>
#include<sys/stat.h>
int main()
{
  struct stat file;
  stat("stat.c",&file);
  printf("st_node = %o\n",file.st_mode);
  return 0;
}
