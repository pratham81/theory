#include<stdio.h>
#include<stdlib.h>
int main()
{
  int ReadyQueue[100],i,n,TotalHeadMov=0,initial;
  printf("enter no of request\n");
  scanf("%d",&n);
  printf("enter the sequence of request\n");
  for(i=0;i<n;i++){
  scanf("%d",&ReadyQueue[i]);
  }
  printf("enter initial head position\n");
  scanf("%d",&initial);
      printf("%d",initial);
  for(i=0;i<n;i++)
  {
    printf(" -> %d",ReadyQueue[i]);
    TotalHeadMov=TotalHeadMov+abs(ReadyQueue[i]-initial);
    initial=ReadyQueue[i];
  }
  printf("\n");
  printf("Total Head Movement=%d",TotalHeadMov);
}
