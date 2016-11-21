#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int curl;
int sqar;
int roud;
int total;

int main()
{
	int t;

	scanf("%d", &t);

	while(t--)
	{
		char seq[1005];

		scanf("%s", seq);

		int i,l;
		int curl=0;
		int sqar=0;
		int roud=0;
		int total=0;

		l=strlen(seq);

		for(i=0; i<l; i++)
		{
			if(seq[i]=='(')
			{
				roud++;
			}

			else if(seq[i]=='{')
			{
				curl++;
			}

			else if(seq[i]=='[')
			{
				sqar++;
			}

			else if(seq[i]==')' && i!=0)
			{
				if(roud!=0)
				{
					roud--;
					total+=2;
				}
			}

			else if(seq[i]==']' && i!=0)
			{
				if(sqar!=0)
				{
					sqar--;
					total+=2;
				}
			}

				else if(seq[i]=='}' && i!=0)
			{
				if(curl!=0)
				{
					curl--;
					total+=2;
				}
			}


		}

		printf("%d\n", total );

	}

	return 0;
}