//Round Robin
#include<stdio.h>
void main()
{
	int i,n,y,count=0,quant,sum=0,wt=0,tat=0,at[20],bt[20],temp[20];
	float avg_wt,avg_tat;
	printf("Enter total no of processes:");
	scanf("%d",&n);
	y=n;
	
	for(i=0;i<n;i++)
	{
		printf("Enter Arrival time and Burst of Process[%d]:\n",i+1);
		printf("Enter arrival time:");
		scanf("%d",&at[i]);
		printf("Enter Busrt time:");
		scanf("%d",&bt[i]);
		temp[i]=bt[i];
	}
	
	printf("Enter Time Quantum:");
	scanf("%d",&quant);
	printf("\nProcess no\tBurst Time\tTurn Around Time\tWaiting Time");
	for(sum=0,i=0;y!=0;)
	{
		if(temp[i]<=quant && temp[i]>0)
		{
			sum=sum+temp[i];
			temp[i]=0;
			count=1;
			
		}
		
		else if(temp[i]>0)
		{
			temp[i]=temp[i]-quant;
			sum=sum+quant;
		}
		
		if(temp[i]==0 && count==1)
		{
			y--;
			printf("\nProcess[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],sum-at[i],sum-at[i]-bt[i]);
			tat=tat+sum-at[i];
			wt=wt+sum-at[i]-bt[i];
			count=0;
		}
		
		if(i==n-1)
		{
			i=0;
		}
	
		else if(at[i+1]<=sum)
		{
			i=i+1;
		}
    
  	    else
   	   {
    		i=0;
	   }
	}
	
	
	
	avg_wt=wt*1.0/n;
	avg_tat=tat*1.0/n;
	printf("\nAverage Waiting Time is %f\n",avg_wt);
	printf("Average Turn around time is %f",avg_tat);
}
