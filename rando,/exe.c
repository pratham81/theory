#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(int argc,char *argv[])
{
int a[100];
int i,j,n,temp;

printf("plz enter how many numbers to print:\n");
scanf("%d",&n);

printf("The array elements are:\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}

for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(a[i]>a[j])
{
temp = a[i];
a[i]=a[j];
a[j]=temp;
}
}
}
printf("The sorted array is:\n");

for(i=0;i<n;i++)
{
printf("%d\n",a[i]);
}

return 0;

}

