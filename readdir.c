#include<stdio.h>
#include<dirent.h>
void main()
{
  DIR * dir;
  struct dirent *dent;
  if((dir=opendir("."))==NULL)
  printf("couldn't open the directory\n");
  else
 {
 while ((dent=readdir(dir))!=NULL)
  printf("%s\n",dent->d_name);
  closedir(dir);
 }
}
