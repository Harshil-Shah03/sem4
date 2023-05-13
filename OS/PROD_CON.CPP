#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int mutex = 1,full = 0,empty =3,x = 0;
void main()
{
	int n; //switch case var
	int down(int);//Down
	int up(int);//up
	void producer();
	void consumer();
	clrscr();
      while(1)
      {
	printf("\n1.)Producer\n2.)Consumer\n3.)Exit.");
	printf("\nEnter Your Choice: ");
	scanf("%d",&n);
	switch(n)
	{
	  case 1:
		if(empty!=0 && mutex==1)
		{
			producer();
		}
		else
		{
			printf("Buffer Full.");
		}
		break;
	  case 2:
		if(full!=0 && mutex==1)
		{
			consumer();
		}
		else
		{
			printf("Buffer Empty.");
		}
		break;
	  case 3:
		exit(0);
		break;

	}
}
	getch();

}

int up(int s)
{
      return  ++s;
}


int down(int s)
{
      return --s;
}


void producer()
{    mutex = down(mutex);
     empty = down(empty);
     x++;
     printf("Item produced at position %d",x);
     full = up(full);
     mutex = up(mutex);
}

void consumer()
{    mutex = down(mutex);
     full = down(full);
     printf("Item consumed at position %d",x);
     x--;
     empty = up(empty);
     mutex = up(mutex);
}


