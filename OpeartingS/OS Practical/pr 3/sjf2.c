#include<stdio.h>

void main()
{
	int at[10],bt[10],temp[10];
	int i,pr,small,time,count=0,end;
	double wt=0,tat=0;
	float avg_wt,avg_tat;
	
	printf("Enter number of process : ");
	scanf("%d",&pr);
	printf("\n");
	
	printf("\nEnter Details of %d Processes : \n", pr);
	for(i=0;i<pr;i++)
	{
		printf("Enter %d Process arrival time : ",(i+1) );
		scanf("%d",&at[i]); 
		printf("Enter %d Process burst time   : ",(i+1));
		scanf("%d",&bt[i]);
		temp[i] = bt[i];
		printf("\n");
	}
	
	bt[9]=9999;
	for(time=0;count!=pr;time++)
	{
		small=9;
		for(i=0;i<pr;i++)
		{
			if(at[i]<=time && bt[i]<bt[small] && bt[i]>0)
			{
				small=i;
			}
		}
		bt[small]--;
		if(bt[small]==0)
		{
			count++;
			end=time+1;
			wt=wt+end-at[small]-temp[small];
			tat=tat+end-at[small];
		}
	}
	
	avg_wt=wt/pr;
	avg_tat=tat/pr;
	printf("Average waiting time    = %lf\n",avg_wt);
	printf("Average turnaround time = %lf\n",avg_tat);
}

