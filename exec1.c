#include<stdio.h>
#include<unistd.h>
int main()
{
 printf("In exec1.c\n");
 char *args[]={"./exec2",NULL};
 execv(args[0],args);
 return 0;
}
