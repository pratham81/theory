#include<stdio.h>
void main(){
	int at[10],bt[10],temp[10];
	int pr,small,time,count=0,end;
	float wt=0,tat=0,avg_wt,avg_tat;
	
	
	
	printf("enter no of process:");
	scanf("%d",&pr);
	printf("\n");

	for(int i=0;i<pr;i++){
	printf("enter %d process arrival time",i+1);
	scanf("%d %d",&at[i],&bt[i]);
	temp[i]=bt[i];	
	}






	bt[9]=9999;
	for(int time=0;count!=pr;time++)
	{
		small=9;
		for(int i=0;i<pr;i++)
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
	printf("average wt%lf",avg_wt);
	printf("average tat%lf",avg_tat);
}
