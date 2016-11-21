#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 100005

struct node 
{
	int data;
	struct node* next;
};

struct list
{
	struct node *head, *tail;
};

int N=0, V=0, C[100005];

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


void addedge(struct list A[], int a, int b)
{
	struct node* t = (struct node*) malloc(sizeof(struct node));
	
	t->data = b;
	t->next = NULL;
	
	if(A[a].tail == NULL)
		A[a].head = t;
	else
		A[a].tail->next = t;
	A[a].tail = t;
}

int color[MAXN], stack[MAXN], top=-1;
enum vertex_color {WHITE, GRAY, BLACK};

int flag=1;

void dfs_visit(struct list A[], int i)
{
	struct node *p; 
	color[i] = GRAY;

	for(p = A[i].head; p != NULL; p = p->next)
	{
		if(color[p->data] == WHITE)
		{
			V++;
			dfs_visit(A, p->data);
		}
		/*else if(color[p->data] == GRAY)
			flag = 0;*/
		// else if condition for topological sort :)

	}

	color[i] = BLACK;
	stack[++top] = i;
}

void dfs(struct list A[], int n)
{
	int i;
	flag = 1;
	top = -1;
	for(i = 1; i<=n; i++)
		color[i] = WHITE;

	for(i = 1; i<=n; i++)
		if(color[i] == WHITE)
		{
			V=1;
			dfs_visit(A, i);
			C[N]=V;
			N++;
		}
}


/*int component_number[MAXN], c = 0;

void dfs_visit2(struct list A[], int i)
{
	struct node *p; 
	color[i] = GRAY;

	for(p = A[i].head; p != NULL; p = p->next)
	{
		if(color[p->data] == WHITE)
			dfs_visit2(A, p->data);
		else if(color[p->data] == GRAY)
			flag = 0;
		// else if condition for topological sort :)

	}

	color[i] = BLACK;
	component_number[i] = c;
}

void dfs2(struct list A[], int n)
{
	int i;
	flag = 1;
	for(i = 1; i<=n; i++)
		color[i] = WHITE;

	for(i = top; i>=0; i--)
	{
		if(color[stack[i]] == WHITE)	
		{
			dfs_visit2(A, stack[i]);
			c++;
		}
	}
}*/

int main()
{
	
	int n,m,i;

	scanf("%d %d", &n, &m);

	struct list A[n+5];

	for(i=1; i<=n; i++)
	{
		A[i].head = A[i].tail = NULL;
	}

	while(m--)
	{
		int x,y;

		scanf("%d %d", &x , &y);

		addedge(A,x,y);
		addedge(A,y,x);
	}

	dfs(A,n);

	mergesort(C,N);

	printf("%d\n", N );

	for(i=N-1;i>=0; i--)
	{
		printf("%d\n", C[i] );
	}

	return 0;


}
