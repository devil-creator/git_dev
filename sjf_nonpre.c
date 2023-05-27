#include<stdio.h>
void waitTime(int process[], int n, int bt[], int wt[], int tat[])
{
	int i;
	wt[0]=tat[0]=0;
	tat[0]=wt[0]+bt[0];
	for(i=1;i<n;i++)
	{
		wt[i]=wt[i-1]+bt[i-1];
		tat[i]=wt[i]+bt[i];
	}	
}
void turnAroundTime(int process[], int n, int bt[], int wt[], int tat[])
{
	int i;
	for(i=0;i<n;i++)
		tat[i]=bt[i]+wt[i];
}
void avgTime (int process[], int n, int bt[])
{
	int wt[n], tat[n], tot_wt=0, tot_tat=0, i;
	float avgWt, avgTat;
	waitTime(process,n,bt,wt,tat);
	printf("\n\tPROCESS\tBT\tWT\tTAT");
	for(i=0;i<n;i++)
	{
		tot_wt+=wt[i];
		tot_tat+=tat[i];
		printf("\n\t%d\t%d\t%d\t%d",process[i],bt[i],wt[i],tat[i]);
	}
	avgWt=(float)tot_wt/n;
	avgTat=(float)tot_tat/n;
	printf("\n\n\tAverage Waiting Time = %.2f",avgWt);
	printf("\n\n\tAverage Turn Around Time = %.2f\n\n",avgTat);
}
void main()
{
	int process[10], n, Bt[10], i, temp;
	printf("\nEnter the number of process : ");
	scanf("%d",&n);
	printf("Enter the burst time of the process :-");
	for(i=0;i<n;i++)
	{
		printf("\nProcess %d : ",(i+1));
		process[i]=i+1;
		scanf("%d",&Bt[i]);
	}
	for(i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(Bt[j]>Bt[j+1])
			{
				temp=Bt[j];
				Bt[j]=Bt[j+1];
				Bt[j+1]=temp;
				temp=process[j];
				process[j]=process[j+1];
				process[j+1]=temp;
			}	
		}
	}		
	avgTime(process,n,Bt);
}
