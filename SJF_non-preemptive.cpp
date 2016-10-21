#include<iostream>
using namespace std;

main()
{
	int n;
	cout<<"No. of PATIENTS-"<<endl;
	cin>>n;
	int at[n],bt[n],t=0,wt[n],tat[n],id[n],sum1=0,sum2=0,swap,swap1,swap2,swap3,small;
	float avgtt,avgwt;
	int condition[n],swap4;
	for(int i=1;i<=n;i++)
	{
		id[i]=i;
		printf("Patient- %d \n",i); 
		printf(" ARRIVAL TIME: "); 
		scanf("%d",&at[i]); 
		printf(" CONSULTION TIME: "); 
		scanf("%d",&bt[i]); 
		/*printf(" PRIORITY: ");
		scanf("%d",&pri[i]);
		printf("\n");*/
		condition[i]=0;
		cout<<endl;
	}
	for (int c = 1;c <n; c++)
  	{
		for (int d = 1 ; d <(n - c); d++)
		{
			if (at[d] > at[d+1]) 
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
  	
	cout<<endl<<endl<<"GANTT CHART---"<<endl;
	cout<<0;
	if(at[1]==0);
	else
	{
		cout<<"   IDLE   "<<at[1];
		t=at[1];
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int l=1;l<=n;l++)
		{
			if(condition[l]==0)     //condition[l]=1(process is finished)
			{
				small=l;
				break;
			};
		}
			
		for(int j=1;at[j]<=t;j++)
		{
			
			if(j>n)
				break;
			if(bt[j]<bt[small] && condition[j]==0)
				small=j;
		}
		
		if(at[small]<=t)
		{
			//cout<<t<<" "<<at[small]<<endl;
			wt[small]=t-at[small];
			tat[small]=wt[small]+bt[small];
			cout<<"   P"<<id[small]<<"   "<<t+bt[small];
			t=t+bt[small];
			condition[small]=1;
		}
		else
		{
			cout<<"   Idle   "<<at[small];
			t=at[small];
			i--;
		}
	}
	cout<<endl<<endl;
	printf("Patients- \tWaiting Time- \tTurn Around Time-\n");
	for(int i=1;i<=n;i++)
	{
		sum1=sum1+wt[i];
		sum2=sum2+tat[i];
		printf("   P%d \t\t     %d \t\t%d\n",i,wt[i],tat[i]);
	}
	cout<<endl;
	avgwt=(float)sum1/n;
	avgtt=(float)sum2/n;
	cout<<"Average Waiting Time="<<avgwt<<endl;
	cout<<"Average Turnaround Time="<<avgtt<<endl;
	
	/*for(int i=1;i<=n;i++)
	
	{
		else
		{
			cout<<"   Idle   "<<at[small];
			t=at[small];
			i--;
		}
		cout<<endl<<endl;
	}*/
}

