#include <stdio.h>



int main()

{
	int t,i,n;

	int arr[1000000]={};//0 - 10^6-1

	// int arr[1000005]={} would also work! (having arr[1000000] will have only 10**6-1 places bt v want 10**6 places to be checked in the main func loop!)

	for(i=0;i<1000001;i++)//0 - 10^6
	{
		arr[i]=0;
	}

	scanf("%d", &t);

	for(i=0; i<t; i++)
	{
		scanf("%d", &n);

		arr[n]++;
	}


		for(i=0; i<1000001; i++)
		{
			while(arr[i]>0)
			{
				printf("%d\n", i );
				arr[i]--;
			}
		}

	

	return 0;
}