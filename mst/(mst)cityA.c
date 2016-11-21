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

/*void countingsort()

{
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

}*/
void merge(struct edge* lft, struct edge* ryt, struct edge* arr, int n, int m)

{
	int i=0,j=0,k=0, nl,nr;

	while(i<n && j<m)
	{
		if(lft[i].weight<ryt[j].weight)
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

int golbal[499501], x;

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
struct edge arr1[499501];
struct edge arr2[499501];
struct papa brr1[499501];
struct papa brr2[499501];

int main()
{
	int t;
	
	x=0;
	sum=0;

	int n,r1, r2,i;

	scanf("%d %d %d", &n, &r1, &r2);

	for(i=0;i<r1;i++)
	{		
		scanf("%d %d %d", &arr1[i].start,&arr1[i].end,&arr1[i].weight );		
	}

    for(i=0;i<r2;i++)
	{		
		scanf("%d %d %d", &arr1[i+r1].start,&arr1[i+r1].end,&arr1[i+r1].weight );
		arr2[i].start=arr1[i+r1].start;
		arr2[i].end=arr1[i+r1].end;
		arr2[i].weight=arr1[i+r1].weight;
	}

		for(i=1;i<=n;i++)
		{
			brr1[i].parent=i;
			brr1[i].rcy=0;
			brr2[i].parent=i;
			brr2[i].rcy=0;
			//brr[i].size=1;
		}

		mergesort(arr1, r1+r2);
		krusk(arr1, brr1, r1+r2);
	
		for(i=0;i<x;i++)
		{
			//printf("%d--%d %d\n", arr1[golbal[i]].start,arr1[golbal[i]].end,arr1[golbal[i]].weight );
			sum += arr1[golbal[i]].weight;

		}
		printf("%d ", sum );
		sum=0;
		x=0;
		mergesort(arr2, r2);
		krusk(arr2, brr2, r2);
	
		for(i=0;i<x;i++)
		{
			//printf("%d--%d %d\n", arr2[golbal[i]].start,arr2[golbal[i]].end,arr2[golbal[i]].weight );
			sum += arr2[golbal[i]].weight;

		}

		printf("%d\n", sum );
		

	return 0;

}