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
int parent[MAXN];
enum vertex_color {WHITE, GRAY, BLACK};

int flag=1;
int visited;
void dfs_visit(struct list A[], int i)
{
	struct node *p; 
	color[i] = GRAY;

	for(p = A[i].head; p != NULL; p = p->next)
	{
		if(color[p->data] == WHITE)
		{
			parent[p->data] = i;
			dfs_visit(A, p->data);
		}
		else if(p->data != parent[i] && color[p->data] == GRAY)
			flag = 0;
		// else if condition for topological sort :)

	}
	visited++;
	color[i] = BLACK;
	stack[++top] = i;
}

void dfs(struct list A[], int n)
{
	int i;
	flag = 1;
	top = -1;
	visited = 0;
	for(i = 1; i<=n; i++)
		color[i] = WHITE;

			dfs_visit(A, 1);

			/* not need to use loop condition here as can be seen in dfs2
			as we jst want tht in one dfs traversal all the number of 
			vertices are visited i.e. vertices==n */

}


int component_number[MAXN], c = 0;

void dfs_visit2(struct list A[], int i)
{
	struct node *p; 
	color[i] = GRAY;

	for(p = A[i].head; p != NULL; p = p->next)
	{
		if(color[p->data] == WHITE)
			dfs_visit2(A, p->data);
		/*else if(color[p->data] == GRAY)
			flag = 0;*/
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
}

int main()
{
	int t;

	scanf("%d", &t);

	while(t--)
	{
		int n,m,i;
		flag = 1;
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

		/*for(i=1; i<=n; i++)
		{
			if(A[i].head == NULL)
			{
				flag=0;
				break;
			}
			

		}*/

		if(flag==0 || visited != n)
		{
			printf("NO\n");
		}


		else
		{
			printf("YES\n");
		}

	}
}