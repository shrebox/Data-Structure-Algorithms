#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int topo=-1;
int topm=-1;

int isempty(int s[])
{
	if(topo==-1)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

void push(int s[], int sm[], int v)
{
	topo++;
	s[topo]=v;

	if(topm==-1)
	{
		topm++;
		sm[topm]=v;
	}

	else
	{
		if(sm[topm]<s[topo])
		{
			topm++;
			sm[topm]=sm[topm-1];
		}

		else
		{
			topm++;
			sm[topm]=s[topo];
		}
	}

	printf("%d\n", s[topo]);
}

void top(int s[])
{
	if(isempty(s))
	{
		printf("-1\n");
	}

	else
	{
		printf("%d\n", s[topo] );
	}
}

void pop(int s[])
{
	if(isempty(s))
	{
		printf("-1\n");
	}

	else
	{
		topo--;
		topm--;
		printf("%d\n", s[topo+1] );

	}
}

void getmin(int s[], int sm[])
{
	if(isempty(s))
	{
		printf("-1\n");
	}

	else
	{
		printf("%d\n", sm[topm] );
	}

}

int main()

{
	int m;

	scanf("%d", &m);

	int stck[m];
	int stckm[m];

	int t;

	scanf("%d", &t);

	while(t--)
	{
		char cmd[10];

		scanf("%s", cmd);

		if(strcmp(cmd, "push")==0)
		{
			int v;

			scanf("%d", &v);

			push(stck,stckm,v);
		}

		else if(strcmp(cmd, "isempty")==0)
		{
			printf("%d\n", isempty(stck));
		}

		else if(strcmp(cmd, "top")==0)
		{
			top(stck);
		}
		else if(strcmp(cmd, "pop")==0)
		{
			pop(stck);
		}

		else
		{
			getmin(stck,stckm);
		}
	}

	return 0;
}