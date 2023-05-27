#include<stdio.h>
void waitTime(int process[],int n,int bt[],int wt[],int tat[])
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
void turnAroundTime(int process[],int n,int bt[],int wt[],int tat[])
{
int i;
for(i=0;i<n;i++)
tat[i]=bt[i]+wt[i];
}
void avgTime(int process[],int n,int bt[])
{
int wt[n],tat[n],tot_wt=0,tot_tat=0,i;
float avgWt,avgTat;
waitTime(process,n,bt,wt,tat);
printf("\n\tProcess\tBT\tWT\tTAT");
for(i=0;i<n;i++)
{
tot_wt+=wt[i];
tot_tat+=tat[i];
printf("\n\t%d\t%d\t%d\t%d",(i+1),bt[i],wt[i],tat[i]);
}
avgWt=(float)tot_wt/n;
avgTat=(float)tot_tat/n;
printf("\n\nAverage Waiting Time=%.2f",avgWt);
printf("\n\nAverage Turn Around time=%.2f",avgTat);
}
void main()
{
int process[10],n,Bt[10],i;
printf("enter number of process:");
scanf("%d",&n);
printf("enter burst time of process");
for(i=0;i<n;i++)
{
printf("\nprocess%d:",(i+1));
scanf("%d",&Bt[i]);
}
avgTime(process,n,Bt);
}

	

