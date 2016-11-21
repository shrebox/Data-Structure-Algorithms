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
	int t;

	scanf("%d", &t);

	while(t--)
	{
		int n,m,i;

		scanf("%d %d", &n, &m);

		int bkv[n];

		for(i=0; i<n; i++)
		{
			scanf("%d", &bkv[i]);
		}

		for(i=n/2; i>=0; i--)
		{
			maxheapify(bkv,i,n);
		}

		

		long long int count=0;

		while(m--)
		{
			int x=bkv[0];

			bkv[0]/=2;

			count+=x-bkv[0];

			maxheapify(bkv, 0, n);
		}

		printf("%lld\n", count );

	}

	return 0;
}