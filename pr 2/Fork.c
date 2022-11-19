#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
void main()
{
pid_t  pid;

int a[5];
int i, j, temp, n;

	printf("\n How many array elements you wants :  ");
	scanf("%d",&n);
	
printf("Enter array\n");
for(i=0;i<n;i++)
{
  scanf("%d",&a[i]);
}

pid=fork();
if(pid==0)
{
  printf("Child process id:%d\n",getpid());
  printf("assending array\n");
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(a[i]>a[j])
      {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
      }
    }
     printf("%d\n",a[i]);
  }
}

else
{
  printf("Parent process id:%d\n",getppid());
  printf("descending array\n");
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(a[i]<a[j])
      {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
      }
    }
    printf("%d\n",a[i]);
  }
}
}

