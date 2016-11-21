#include <stdio.h>
#include <stdlib.h>

int main()

{
	int i,j,k,t,n;

	scanf("%d", &t);

	for(i=0; i<t; i++)
	{
		scanf("%d", &n);

		int arr[n], *a=arr;

		for(j=0; j<n; j++)
		{
			scanf("%d", a+j);
		}

		for(j=0; j<n-1; j++)
		{
			int place=j;

			for(k=place+1; k<n; k++)
			{
				if(*(a+place)>*(a+k))
				{
					place=k;

				}
			}

			int temp;
			temp=*(a+j);
			*(a+j)=*(a+place);
			*(a+place)=temp;
		}

		for(j=0; j<n; j++)
		{
			printf(" %d", *(a+j) );
		}
		printf("\n");
	}

	return 0;
}