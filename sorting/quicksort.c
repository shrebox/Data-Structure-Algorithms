#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int i, int j)
{
	int temp;
		
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
}

int partition(int * arr, int p, int r)
{
	int x, i,j;

	x=arr[r];

	i=p-1;

	for(j=p; j<=r-1; j++)
	{
		if(arr[j]<=x)
		{
			i+=1;
			swap(arr,i,j);

		}
	}

	swap(arr, i+1, r);

	return i+1;
}

void quicksort(int * arr, int p, int size)
{
	int r, q;

	r=size;

	if(p<r)
	{
		q= partition(arr, p, r);

		quicksort(arr, p, q-1);
		quicksort(arr, q+1, r);
	}
}


int main()

{
	int n;

	printf("Enter size of the array:");
	scanf("%d", &n);

	int a[n], k;

	for(k=0; k<n; k++)
	{
		scanf("%d", &a[k]);
	}

	quicksort(a, 0, n-1);

	for(k=0; k<n; k++)
	{
		printf("%d", a[k]);
	}
	printf("\n");





	return 0;


}