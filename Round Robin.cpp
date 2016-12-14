#include <stdio.h>
#define MAX 50

main()
{
	int i,n,m,j=0;
	int b[20],b1[20],f[20],w[20];
	int start=0,finish=0,total=0,t;
	float aw=0.0,at=0.0;
	printf("Enter the no. of process");
	scanf("%d",&n);
	printf("Enter the time quantum");
	scanf("%d",&t);
	
	for(i=1;i<=n;i++)
	{
		printf("Enter the burst time of the process %d",i);
		scanf("%d",&b[i]);
		b1[i]=b[i];
		total=total+b[i];
	}
	start=0;
	
	while (j<total)
		for(i=1;i<=n;i++)
	
	if(b[i]==0)
		continue;
	
	if(b[i]>t)
	{
		finish=start+t;
		j=j+t;
		start=finish;
		b[i]=b[i]-t;
	}
	
	else
	{
		finish=start+b[i];
		j=j+b[i];
		start=finish;
		f[i]=finish;
		b[i]=0;
		w[i]=finish-b1[i];
	}

	printf("\n\nProcess No\tbursttime\t WaitingTime\t TurnAroundTime");
	
	for(i=1;i<=n;i++)
	{
		printf("\n\np%d\t\t%3d\t\t%3d\t\t%3d",i,b1[i],w[i],f[i]);
		aw=aw+w[i];
		at=at+f[i];
	}
	
	aw=aw/(float)n;
	at=at/(float)n;
	printf("\n Average Waiting Time : %0.2f",aw);
	printf("\n Average Turn Around Time : %0.2f ",at);
}
