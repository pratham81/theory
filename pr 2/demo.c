#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
void main()
{
pid_t pid;
int a,b,c;
printf("enter 2 numbers\n");
scanf("%d%d",&a,&b);
pid=fork();
                 if(pid==0)                               
                 {
                c=a+b;
                printf("Child performed addition add=%d\n",c);
                 }
                 else
                 {
                 c=a-b;
                printf("Parent performed Subtraction SUB=%d\n",c);
              
                 }
                 
 }
