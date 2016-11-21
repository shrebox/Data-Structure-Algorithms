#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct papa
{
	int parent, rcy;
};

struct papa brr[100005];
int max=1,min;

int find(int kb)
{
	while(brr[kb].parent!=kb)
	{
		kb=brr[kb].parent;
	}
	return kb;

}

void uniony(int p, int q)
{
	int i, j, x, y;

	i=find(p);
	j=find(q);

	if(i!=j)
	{

		//x=find(i);
		//y=find(j);

		if(brr[i].rcy<brr[j].rcy)
		{
			brr[i].parent=j;
			brr[j].rcy+=brr[i].rcy;
			
			if(max<brr[j].rcy)
			{
				max=brr[j].rcy;
			}
		}
		else
		{
			brr[j].parent=i;
			brr[i].rcy+=brr[j].rcy;

			if(max<brr[i].rcy)
			{
				max=brr[i].rcy;
			}
		}
	}
}



int main()
{
	int n,q,i,k;

	scanf("%d %d", &n, &q);

	for(i=1;i<=n;i++)
	{
		brr[i].parent = i;
		brr[i].rcy = 1;
	}

	while(q--)
	{
		char cmd[10];

		scanf("%s", cmd);

		if(strcmp(cmd,"M")==0)
		{
			int a,b;

			scanf("%d %d", &a, &b);

			uniony(a,b);
		}

		else if(strcmp(cmd,"Q")==0)
		{
			int a;

			scanf("%d", &a);

			k=find(a);

			printf("%d\n", brr[k].rcy );
		}

		else if(strcmp(cmd,"MAX")==0)
		{
			printf("%d\n", max );
		}

		else
		{
			min=100005;

			for(i=1;i<=n;i++)
			{
				k=find(i);

				if(min>brr[k].rcy)
				{
					min=brr[k].rcy;
				}
			}

			printf("%d\n", min );
		}

	}
}