#include<stdio.h>
#include<conio.h>
int i, j, k,z, p[100], ind[50], n, nf, pgfcnt = 0,hit,head,opt,lru_cnt[50],freq[50];

void getData() {
    printf("Enter the length of ref: ");
    scanf("%d", &n);
    printf("Enter the length of frame: ");
    scanf("%d", &nf);
    printf("Enter the sequence \n");
    for (i = 0; i < n; i++) {
	printf("at pos %d: ", i + 1);
	scanf("%d", &ind[i]);
    }
}

void initialize() {
    pgfcnt=0;
    for (i = 0; i < nf; i++) {
	p[i] = -1; // Changed the initialization value to -1
	freq[i] =0;
    }
}

int isHit(int data) {
    hit=0;

	for (i = 0; i < nf; i++) {
	if (p[i] == data) {
	    hit = 1;
	    freq[i]++;

	    break;
	}
    }

    return hit;
}

void dispPages() {
    for (i = 0; i < nf; i++) {
	if (p[i] != -1) // Changed the condition to check for -1
	    printf("%d ", p[i]);
    }
}

void dispPgfcnt() {
    printf("\nTotal no of page fault: %d", pgfcnt);
}

void fifo() {
    initialize();
     head=0;
    for (k = 0; k < n; k++) {
	printf("\nFor %d:",ind[k]);
	if (isHit(ind[k]) == 0) {
	    p[head]=ind[k];
	    head=(head+1)%nf;
	    pgfcnt++;
	    dispPages();
	} else {
	    printf("HIT\n");
	}
    }
    dispPgfcnt();
}

int getOptpg(int start)
{
 int opt_pg=-1;
 int max_dis=-1;
 for(i=0;i<nf;i++)
 {int dist = 0;
  for(j=start;j<n;j++)
 { dist++;
   if(p[i]==ind[j])
   break;

  }
  if(dist>max_dis)
  {
  max_dis = dist;
  opt_pg= i;

  }


 }//page loop
 return opt_pg;
}//end of opt page

void optimal()
{
 initialize();

 for(k=0;k<n;k++)
 {
  printf("\nFor %d: ",ind[k]);
  if(isHit(ind[k])==0)
  { if(p[nf-1]==-1)
    {
	for(i=0;i<nf;i++){
	if(p[i]==-1)
       { p[i]=ind[k];
       break;} }//for loop


    }
       else
       {
	 opt = getOptpg(k) ;
	 p[opt]=ind[k];
       }//else ends
       pgfcnt++;
   dispPages();
  }
    else
    {
    printf("HIT");
    }
 }//ref loop ends
 dispPgfcnt();
} //optimal ends

int getLrupg()
	{
	 int min_cnt = lru_cnt[0];
	 int lru_i=0;
	 for(i=1;i<nf;i++)
	 {
	    if(lru_cnt[i]<min_cnt)
	  {  min_cnt=lru_cnt[i];
	    lru_i =i;}


	 }
	 return lru_i;


	}//lrupage endsd
void lru()
{  int roi;
   initialize();
   for(k=0;k<n;k++)

   { printf("\nFor %d: ",ind[k]);
   if(isHit(ind[k])==0)
   {
      if(p[nf-1]==-1)
      {
       for(z=0;z<nf;z++)
	{if(p[z]==-1)
	 {p[z]=ind[k];
	 lru_cnt[z]=k+1;
	 break;}
	}//nf for loop ends
       }//nf if ends
       else
      {
      roi = getLrupg();
       p[roi]=ind[k];
       lru_cnt[roi] =k+1;
      }
   dispPages();
   pgfcnt++;

   }//if ishit ends
   else
  { printf("HIT");
   lru_cnt[i]=k+1;}//else ends


   }//ref for loop ends
   dispPgfcnt();
}//lru_ends

int getLfupg()
{ int min_freq,lfu_ind;
 min_freq = freq[0];
 lfu_ind=0;
 for(i=0;i<nf;i++)
 {
  if(freq[i]<min_freq)
  {
    min_freq =freq[i];
    lfu_ind=i;

  }
 }
 return lfu_ind;
}//get lfu ends

void lfu()
{  int lfu_pg=0;
 initialize();
 for(k=0;k<n;k++)
 {
 printf("\nFor %d: ",ind[k]);
  if(isHit(ind[k])==0)
  {
   if(p[nf-1]==-1)
   {
   for(j=0;j<nf;j++)
   {
   if(p[j]==-1)
   {
    p[j]=ind[k];
    freq[j]++;
    break    ;
   }
   }
   }//start if ends
   else
   {
     lfu_pg = getLfupg();
     p[lfu_pg] = ind[k];
     freq[lfu_pg]=1;
   }//start else ends
   dispPages();
   pgfcnt++;
  }//ishit if ends
  else{
  printf("HIT");
  }
 }//k loop ends
 dispPgfcnt();
}//lfu ends

void main() {
    clrscr();
    getData();
    lfu();
    getch();
}