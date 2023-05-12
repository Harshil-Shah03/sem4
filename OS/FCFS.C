#include<stdio.h>
#include<conio.h>
//to swap
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b ;
	*b = temp;
}
void main()
{
	int pro[100],at[100],bt[100],ct[100],tat[100],wt[100],ttat=0,twt=0,atat,awt;
	int n,i,j,prevbt;
	clrscr();
	printf("Enter nos of processes ");
	scanf("%d",&n);
	for(i = 0;i<n;i++)
	{
	 printf("Enter arrival time and burst time for process %d \n",i+1);
	 scanf("%d %d",&at[i],&bt[i]);
	 pro[i] = i+1;
	}

	//sort
	for(i =0; i<n-1;i++)
	{
		for(j = 0; j<n-1;j++)
		{
			if(at[j]>at[j+1])
			{
			  swap(&at[j],&at[j+1]);
			  swap(&bt[j],&bt[j+1]);
			  swap(&pro[j],&pro[j+1]);
			}


		}
	}
	//Calculate completion timed
	prevbt = 0;
	for(i =0;i<n;i++)
	{
	 ct[i]=prevbt+bt[i];
	 printf("%d",prevbt);
	 prevbt = ct[i];
	 printf("%d",prevbt);

	}
	//Calculate turnaround time and waiting time
	for(i = 0;i < n ; i++)
	{
	 tat[i] = ct[i] - at[i];
	 wt[i]  = tat[i] - bt[i];
	}
	for(i =0;i<=n;i++)
	{
	 ttat+=tat[i];
	 twt+= wt[i];
	}
	atat = ttat/n;
	awt = twt/n;
	printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
	for(i = 0;i<n; i++)
	{
	 printf("\n%d\t%d\t%d\t%d\t%d\t%d\n",pro[i],at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	printf("average tat %d: ",atat);
	printf("waiting t %d: ",awt);
//gantt chart
	for( i =0;i<n;i++)
	{
	printf("|P%d|%d|",pro[i],ct[i]);
	}

	getch();
}
