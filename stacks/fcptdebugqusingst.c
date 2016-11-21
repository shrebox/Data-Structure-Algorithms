#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top1 = -1;
int top2 = -1;
int countop = 0;

int isempty()
{
	if(top1==-1 && top2==-1)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

void push(int a[], int v)
{
	top1++;
	a[top1]=v;
	printf("%d 1\n", a[top1] );
}

void pop(int a[], int b[])
{
	if(isempty())
	{
		printf("-1 0\n");
	}

	else
	{
		/*int countop = 0;

		while(top1!=-1)
		{
			top2++;
			b[top2]=a[top1];
			top1--;
			countop++;
		}

		printf("%d %d\n", b[top2], countop );

		while(top2!=-1)
		{
			top1++;
			a[top1]=b[top2];
			top2--;
		}*/

		if(top2!=-1)
		{
			top2--;
			printf("%d 1\n", b[top2+1] );
		}

		else
		{
			int countop = 1;  //counttop=1 as 1 step is used to pop out the final element

			while(top1!=-1)
			{
				top2++;
				b[top2]=a[top1];
				top1--;
				countop+=2;
			}

			printf("%d %d\n", b[top2], countop );
			top2--;



		}
	}
}

void top(int a[], int b[])
{
	if(isempty())
	{
		printf("-1 0\n");
	}

	else
	{

		if(top2!=-1)
		{
			
			printf("%d 0\n", b[top2] );
		}
		else
		{
			
			int countop = 0;

			while(top1!=-1)
			{
				top2++;
				b[top2]=a[top1];
				top1--;
				countop+=2;
			}
			printf("%d %d\n", b[top2], countop);

		}

		/*while(top2!=-1)
		{
			top1++;
			a[top1]=b[top2];
			top2--;
		}*/
	}
}

void enqueue(int a[], int v)
{
	push(a,v);
}

void dequeue(int a[], int b[])
{
	pop(a,b);
}

void front(int a[], int b[])
{
	top(a,b);	
}

int main()
{
	int t,i;

	scanf("%d", &t);
    int s1[105], s2[105];
	while(t--)
	{
	    /*printf("1:");
	    for(i=0; i<=top1; i++)
            printf(" %d",s1[i]);
        printf("\n2: ");
        for(i=0; i<=top2; i++)
            printf(" %d",s2[i]);
        printf("\n");*/

		char cmd[10];

		scanf("%s", cmd);

		if(strcmp(cmd, "enqueue")==0)
		{
			int v;

			scanf("%d", &v);

			enqueue(s1,v);
		}

		else if(strcmp(cmd, "dequeue")==0)
		{
			dequeue(s1,s2);
		}

		else if(strcmp(cmd, "isempty")==0)
		{
			if(isempty())
			{
				printf("1 0\n");
			}

			else
			{
				printf("0 0\n");
			}
		}

		else if(strcmp(cmd, "front")==0)
		{
			front(s1, s2);
		}
	}

	return 0;
}

