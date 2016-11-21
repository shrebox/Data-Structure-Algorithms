#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int i, int largest)
{
	int temp;
		
		temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
}

void maxheapify(int *a, int i, int size)
{
	int l,r, largest;

	l=2*i+1;
	r=2*i+2;

	if(l<size && a[l]>a[i])
	{
		largest=l;
	}

	else
	{
		largest=i;
	}

	if(r<size && a[r]>a[largest])
	{
		largest=r;
	}

	if(largest!=i)
	{
		swap(a,i,largest);
		maxheapify(a,largest,size);
	}

	

}

int main()

{
	int t,i;

	scanf("%d", &t);

	int bkv[t];

	for(i=0; i<t; i++)
	{
		scanf("%d", &bkv[i]);
	}


		for(i=t/2; i>=0; i--)
		{
			maxheapify(bkv,i,t);
		}

		for(i=t-1; i>=0; i--)
		{
			swap(bkv, 0, i);
			maxheapify(bkv, 0, i);
		}

	for(i=0; i<t; i++)
	{
		printf("%d\n", bkv[i] );
	}

	return 0;
}