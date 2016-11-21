#include <stdio.h>
#include <stdlib.h>

struct edge
{
	int start,end,weight;	

};

struct papa
{
	int parent, rcy;
};

void merge(struct edge* lft, struct edge* ryt, struct edge* arr, int n, int m)

{
	int i=0,j=0,k=0, nl,nr;

	while(i<n && j<m)
	{
		if(lft[i].weight>ryt[j].weight)
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

int mergesort(struct edge *arr1, int l)

{
	int mid, midl, midr;

	if(l<2)
	{
		return 0;
	}

	if(l%2==0)
	{
		mid= l/2;

	int i;
	struct edge left[mid], right[l-mid], *x=left, *y=right;

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

	int i;
	struct edge left[midl], right[midr], *x=left, *y=right;

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

int find(struct papa b[], int kb)
{
	while(b[kb].parent!=kb)
	{
		kb=b[kb].parent;
	}
	return kb;
}

void uniony(struct papa b[], int p, int q)
{
	int i,j;

	i=find(b,p);
	j=find(b,q);

	if(b[i].rcy<b[j].rcy)
	{
		b[i].parent=j;
	}

	else if(b[i].rcy>b[j].rcy)
	{
		b[j].parent=i;
	}

	else
	{
		b[j].parent=i;
		b[i].rcy++;
	}
}

int golbal[100005], x;

void krusk(struct edge a[], struct papa b[], int m)
{
	int i,p,q;
	x = 0;
	for(i=0;i<m;i++)
	{
		p=find(b,a[i].start);
		q=find(b,a[i].end);
		if(p!=q)
		{
			golbal[x++]=i;
			uniony(b,p,q);
		}
	}

}

int sum=0;
struct edge arr[100005];
struct papa brr[100005];

int main()
{
	int t;

	scanf("%d", &t);

	while(t--)
	{
	
	x=0;
	sum=0;

	int n,m,i;

	scanf("%d %d", &n, &m);

	for(i=0;i<m;i++)
	{		
		scanf("%d %d %d", &arr[i].start,&arr[i].end,&arr[i].weight );		
	}

		for(i=1;i<=n;i++)
		{
			brr[i].parent=i;
			brr[i].rcy=0;
			//brr[i].size=1;
		}

		mergesort(arr,m);
		krusk(arr, brr, m);
	
		for(i=0;i<x;i++)
		{
			//printf("%d--%d %d\n", arr[golbal[i]].start,arr[golbal[i]].end,arr[golbal[i]].weight );
			sum += arr[golbal[i]].weight;

		}

		printf("%d\n", sum );

	
	}
	

	return 0;

}