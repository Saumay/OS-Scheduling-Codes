#1)FCFS

#include<iostream>
#include<stdio.h>

using namespace std;

main()
{
	int n;
	cout<<"No. of patients-";
	cin>>n;
	int at[n],bt[n],t=0,wt[n],id[n],tat[n],sum1=0,sum2=0,swap1,swap2,swap3;
	float avgtt,avgwt;
	for(int i=1;i<=n;i++)
	{
		id[i]=i;
		printf("Patient- %d \n",i); 
		printf(" ARRIVAL TIME: "); 
		scanf("%d",&at[i]); 
		printf(" CONSULTION TIME:"); 
		scanf("%d",&bt[i]); 
		printf("\n");
	}
	
	for (int c = 1;c <n; c++)
  	{
		for (int d = 1 ; d <(n - c); d++)
		{
		  if (at[d] > at[d+1]) /* For decreasing order use < */
		  {
			swap1=at[d];
			at[d]=at[d+1];
			at[d+1]=swap1;
			
			swap2=bt[d];
			bt[d]=bt[d+1];
			bt[d+1]=swap2;
			
			swap3=id[d];
			id[d]=id[d+1];
			id[d+1]=swap3;
		  }
		}
	}

	cout<<"Gantt Chart---"<<endl;
	cout<<0;
	for(int i=1;i<=n;i++)
	{
		if(at[i]<=t)
		{
			wt[i]=t-at[i];
			tat[i]=wt[i]+bt[i];
			cout<<"  P"<<id[i]<<"  "<<t+bt[i];
			t=t+bt[i];
		}
		else
		{
			cout<<"   Idle   "<<at[i];
			t=at[i];
			i--;
		}
	}
	
	cout<<endl<<endl;
	printf("Patients- \tWaiting Time- \tTurn Around Time-\n");
	for(int i=1;i<=n;i++)
	{
		sum1=sum1+wt[i];
		sum2=sum2+tat[i];
		printf("   P%d \t\t     %d \t\t      %d\n",i,wt[i],tat[i]);
	}
	
	cout<<endl;
	avgwt=(float)sum1/n;
	avgtt=(float)sum2/n;
	cout<<"Average Waiting Time--"<<avgwt<<endl;
	cout<<"Average Turnaround Time--"<<avgtt<<endl;
}


