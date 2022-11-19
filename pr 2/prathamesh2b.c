#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
pid_t pid;
pid=fork();
if(pid==0){
	printf("child process%d\n",pid);
	printf("return type child %d\n",getpid());
	printf("%d\n",getppid());
	}
else{
	printf("parent process%d\n",pid);
	printf("return type parent %d\n",getpid());
	printf("%d\n",getppid());
	}
return 0;
}
