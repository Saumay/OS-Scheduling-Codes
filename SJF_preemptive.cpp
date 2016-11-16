#include<iostream>
using namespace std;

main()
{
	int n;
	cout<<"No. of patients-"<<endl;
	cin>>n;
	int at[n],bt[n],bt2[n],t=0,wt[n],tat[n],id[n],sum1=0,sum2=0,swap,swap1,swap2,swap3,small;
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
		bt2[i]=bt[i];
		condition[i]=0;
		wt[i]=-at[i];
		cout<<endl;
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
    
      //cout<<"at="<<at[d];
		swap4=wt[d];
		wt[d]=wt[d+1];
		wt[d+1]=swap4;
	  }
    }
  	}
  	
  	cout<<"GANTT CHART---"<<endl;
	int ct=0;
	cout<<ct;
	//int ll=0;
	while(1)
	{
		int dur=0,ct_past=0,count=0;
		for(int i=1;i<=n;i++)
		{
			if(condition[i]==-1)
				count++;
			else if(condition[i]==0 && at[i]<=ct)
			{
				small=i;
			}
		}
		//cout<<"small-"<<small;
		
		//cout<<"   ";
		
		
		if(count==n)
			break;
		
		for(int j=1;at[j]<=ct;j++)
		{	
			if(j>n)
				break;
			if(bt[j]<bt[small] && bt[j]>0 && condition[j]==0)
				small=j;
		}
		
		ct_past=ct;
		
		if(ct<at[n])
		{
			for(int i=1;i<=n;i++)
			{
				if(at[i]>ct)
				{
					ct=at[i];
					break;
				}
			}
		}
		else if(ct>=at[n])
		{
			ct=ct+bt[small];
		}
		
		dur=ct-ct_past;
		bt[small]=bt[small]-dur;
		for(int k=1;k<=n;k++)
		{
			if(condition[k]==0 && k!=small)
			{
				wt[k]=wt[k]+dur;
			}
		}
		
		if(bt[small]<=0)
		{
			condition[small]=-1;
		}
		cout<<"   P"<<id[small]<<"   "<<ct;
		//ll++;
		
		/*cout<<"WAITING TIME ARRAY--";
		cout<<endl<<"CONDITION ARRAY--"<<endl;
		for(int i=1;i<=n;i++)
			cout<<condition[i]<<" ";*/

	}
	cout<<endl<<endl;
	for(int i=1;i<=n;i++)
	{
		tat[i]=wt[i]+bt2[i];
	}
	
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
