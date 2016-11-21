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

struct q
{
	int info;
	struct q* ptr;
};

struct q* front;
struct q* end;
struct q* temp;
struct q* start;

int count = 0;
int sum=0;


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

void enqueue(int data)
{
    if (end == NULL)
    {
        end = (struct q *)malloc(sizeof(struct q));
        end->ptr = NULL;
        end->info = data;
        front = end;
    }
    else
    {
        temp=(struct q *)malloc(sizeof(struct q));
        end->ptr = temp;
        temp->info = data;
        temp->ptr = NULL;
 
        end = temp;
    }
    count++;
}


int dequeue()
{
    start = front;
    //struct q* tempo;
    int tempo;
 
    if (start == NULL)
    {
        
        return -1;
    }
    else
    	
        if (start->ptr != NULL)
        {
            start = start->ptr;
            tempo = front->info;
            free(front);
            front = start;
        }
        else
        {
            tempo = front->info;
            free(front);
            front = NULL;
            end = NULL;
        }
        count--;

        return tempo;
}

int isempty()
{
     if ((front == NULL) && (end == NULL))
        return 1;
    else
       return 0;
}


int color[MAXN], stack[MAXN], top=-1;
enum vertex_color {WHITE, GRAY, BLACK};

int flag=1;

void bfs(struct list A[], int n, int s)
{
	int i,u,dist[MAXN], sum = 0;

	struct node *p; 

	flag = 1;
	top = -1;
	
	for(i = 0; i<n; i++)
	{
		color[i] = WHITE;
		dist[i] = 0;
	}

	color[s] = GRAY;

	front=end=NULL;

	enqueue(s);

	while(!isempty())
	{
		u = dequeue();

		for(p = A[u].head; p != NULL; p = p->next)
		{
			if(color[p->data] == WHITE)
			{
				dist[p->data] = 1 + dist[u];
				color[p->data] = GRAY;
				enqueue(p->data);
			}
		
		}
		sum += dist[u];
		color[u] = BLACK;

	}
	printf("%d\n", sum);


}


int main()
{
	int n,m,k,i;

	scanf("%d %d %d", &n, &m, &k);

	struct list A[n+5];

	for(i=0; i<n; i++)
	{
		A[i].head = A[i].tail = NULL;
	}

	while(m--)
	{
		int u,v;

		scanf("%d %d", &u, &v);

		addedge(A,u,v);
		addedge(A,v,u);

	}

	while(k--)
	{
		int r;

		scanf("%d", &r);

		bfs(A,n,r);

		//printf("%d\n", sum );
	}


	return 0;



}