#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	int val;
	struct node* next;

};

struct node* head;
struct node* cur;

void display()
{
    struct node *temp;
    temp=head->next;
    while(temp!=NULL)
    {
   	 	printf("%d->",temp->val);
    	temp=temp->next;
    }


}

void smplinsrt(int num)
{
	
	struct node* newnode = (struct node*) malloc(sizeof(struct node));
	
	cur->next=newnode;
	newnode->next=NULL;
	newnode->val=num;
	cur=newnode;
	
}

struct node* Insert(struct node* head, int val)
{
	struct node* newnode = (struct node*) malloc(sizeof(struct node));
	struct node* prev;


	cur = head;
	while(cur!=NULL && cur->val<=val)
	{
		prev=cur;
		cur=cur->next;
	}
	
	prev->next=newnode;
	newnode->next=cur;
	newnode->val=val;
	printf("%d\n", val );

	//display();
	
	return newnode;



}

struct node* deleteDuplicate(struct node*head)
{
	struct node* prev;
	prev=cur;
	int deleted = 0;
	
	while(cur->next!=NULL)
	{
		if(cur->val==cur->next->val)
		{
			prev->next = cur->next;
			printf("%d ", cur->val);
			free(cur);
			deleted = 1;
			cur = prev->next;

		}
		else
		{

			prev=cur;
			cur=cur->next;
		}
	}
	if(!deleted)
	{
		printf("-1");
	}
	printf("\n");

	//display();
}

void print(int indi)
{

	cur = cur->next;

	while(cur && indi--)
	{
		cur = cur->next;
	}

	if(cur == NULL)
	{
		printf("-1\n");
	}

	else
	{
		printf("%d\n", cur->val );
	}

	//display();
}



int main()
{
	int t;

	scanf("%d", &t);

	while(t--)
	{

		head = (struct node*) malloc(sizeof(struct node));
		head->val = -1;
		head->next = NULL;
		cur=head;

		int num=-1;
		
		while(1)
		{
			scanf("%d", &num);
			if(!num)
				break;
			smplinsrt(num);
		}

		//printf("Donesimpleinsert\n");
		int q;

		scanf("%d", &q);

		while(q--)
		{

			cur=head;

			char cmd[10];

			scanf("%s", cmd);

			if(strcmp(cmd, "Insert")==0)
			{
				int v;

				scanf("%d", &v);

				cur=head;	

				Insert(cur,v);
			}

			else if(strcmp(cmd, "Delete")==0)
			{
				cur=head;

				deleteDuplicate(cur);
			}

			else if(strcmp(cmd, "Print")==0)
			{
				int index;

				scanf("%d", &index);

				cur=head;

				print(index);
			}

		}
	}	

		return 0;
}
