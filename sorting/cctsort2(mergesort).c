#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int* lft, int* ryt, int* arr, int n, int m)

{
	int i=0,j=0,k=0, nl,nr;

	while(i<n && j<m)
	{
		if(*(lft+i)<*(ryt+j))
		{
			*(arr+k)=*(lft +i);
			k++;
			i++;

		}

		else
		{
			*(arr+k)=*(ryt +j);
			k++;
			j++;
		}
	}

	while(i<n)
	{
		*(arr+k)=*(lft +i);
		k++;
		i++;
	}

	while(j<m)
	{
		*(arr+k)=*(ryt +j);
		k++;
		j++;
	}

}

int mergesort(int* arr1, int l)

{
	int mid, midl, midr;

	if(l<2)
	{
		return 0;
	}

	if(l%2==0)
	{
		mid= l/2;

	int i,left[mid], right[l-mid], *x=left, *y=right;

	for(i=0; i<mid; i++)
	{
		*(x+i)=*(arr1+i);
	}

	for(i=0; i<mid; i++)
	{
		*(y+i)=*(arr1 + (mid+i));
	}

	mergesort(x, mid);
	mergesort(y, mid);
	merge(x,y,arr1,mid,mid);
	}

	else
	{
		midl=(l+1)/2;
		midr=l-midl;

	int i,left[midl], right[midr], *x=left, *y=right;

	for(i=0; i<midl; i++)
	{
		*(x+i)=*(arr1+i);
	}

	for(i=midr+1; i<l; i++)
	{
		*(y+(i-midl))=*(arr1+i);
	}

	mergesort(x, midl);
	mergesort(y, midr);
	merge(x,y,arr1,midl,midr);
	}


}

int main()

{
	int n,i,j;

	scanf("%d", &n);

	int arr[n+1];
	int *a=arr;


	for(i=0; i<n; i++)
	{
		scanf("%d", a+i);

	}

	if (mergesort(a, n))
	{

	for(i=0; i<n; i++)
	{
		printf("%d", *(a+i) );
	}

	}

	return 0;


}