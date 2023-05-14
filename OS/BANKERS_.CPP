#include<stdio.h>
#include<stdlib.h>

int main()
{
int alloc[5][3],max[5][3],avail[3],need[5][3],n=5,m=3,i,j,k,v[5],ans[5],ind=0;
printf("Enter avail resources");
for(j=0;j<m;j++) scanf("%d",&avail[j]);
for(i=0;i<n;i++)
{
  printf("ENter alloc for P%d\n",i);
  for(j=0;j<m;j++)
		{
			scanf("%d",&alloc[i][j]);

		}//j loop
      printf("\nEnter max for P%d\n",i);
	for(j=0;j<m;j++)
		{ scanf("%d",&max[i][j]);
		}//j loop
}//i loop
for(i=0;i<n;i++)
{ v[i]=0;
 for(j=0;j<m;j++)
		{
		need[i][j] = max[i][j]-alloc[i][j];
		}//j loop
}//i loop


for(k=0;k<n;k++)
{
for(i=0;i<n;i++)
{
  if(v[i]==0)
  {
	int flag = 0;


  for(j=0;j<m;j++)
		{
		if(need[i][j]>avail[j]) {flag=1;
		break;}
		}//j loop
  if (flag==0)
  {  v[i]=1;
     ans[ind++]=i;
     for(j=0;j<m;j++) avail[j]+=alloc[i][j];

  }//flag if block ends

  }//v[i] if block
}//i loop
}//k loop
int flag2 = 0;
for(i=0;i<n;i++)
{
   if(v[i]==0) flag2=1;
}
if (flag2==1) printf("Deadlock");
else
{
 for (i=0;i<n;i++)
 printf("P%d-->",ans[i]);
}//else






return 0;
}//main ends