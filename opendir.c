#include<stdio.h>
#include<dirent.h>
void main()
{
  DIR * dir;
  dir= opendir(".");
  if(dir==NULL)
  printf("couldn't open the directory\n");
  else
 {
  printf("Opened the directory\n");
}
}
