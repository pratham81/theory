#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
pid_t pid;
pid=fork();
int arr[]={45,2,5,8,1};
int a;
if(pid==0)
{
	for(int i=0;i<4;i++){
	for(int j=i+1;j<5;j++){
	if(arr[j]<=arr[i]){
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}
}
}
for(int i=0;i<=4;i++)
	printf("%d\n",arr[i]);
}
else{
scanf("%d\n",&a);
for(int i=0;i<=4;i++){
if(a==arr[i]){
	printf("element found\n");
	return 0;
	}
}
}
return 0;
}
