#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
	int val;
	struct node* next;
	struct node* prev;

};

struct node* head;
//struct node* headn;
struct node* cur;
//struct node* curn;
int size=0;

void display()
{
    struct node *temp;
    temp=head->next;
    while(temp!=NULL)
    {
   	 	printf("%d ",temp->val);
    	temp=temp->next;
    }

}


void displayrev()
{
	//printf("holo\n");

    struct node *temp;
    temp=head;
    
    while(temp->next!=NULL)
    {
   	 	printf("%d ",temp->val);
    	temp=temp->next;
    }

}

void insrtend(int num)
{
	
	struct node* newnode = (struct node*) malloc(sizeof(struct node));
	
	cur->next=newnode;
	newnode->next=NULL;
	newnode->val=num;
	cur=newnode;
	
}

void insrtstart(int num)
{
	
	struct node* newnode = (struct node*) malloc(sizeof(struct node));
	
	newnode->next=head->next; 
	newnode->val=num;
	head->next=newnode;
	if (size==0)
		cur = newnode;
	
}


void rev()
{	
	//printf("reched");
	struct node* prev = NULL;
	struct node* cur1 = head;
	struct node* next1;

	while(cur1!=NULL)
	{
		next1=cur1->next;
		cur1->next=prev;
		prev=cur1;
		cur1=next1;

	}

	head=prev;

	
}

void deletenext(int i,int m)
{
	if(head->next==NULL)
	{
		return;
	}

	else
	{
		struct node*temp;
		struct node*temp2;

		temp=head;

		while(i--)
		{
			if(temp->next!=NULL)
			{
				temp=temp->next;
			}
			else
			{
				return;
			}
		}

		temp2=temp;

		while(m--)
		{

			temp=temp2;

			if(temp->next!=NULL)
			{

				
				temp=temp->next;
				temp2->next=temp->next;
				if (temp->next!=NULL)
				{
					temp->next->prev=temp2;
				}
				free(temp);
			}

			else
			{
				return;
			}
		}



	}

}


void printList(struct node* head){

    struct node* current = head;
    while(current != NULL){
        printf("%d ",current->val);
        current = current->next;
    }
    printf("\n");

}

void partition(struct node * head, struct node **front, struct node **back){

    struct node * fast;
    struct node * slow;

    if (head == NULL || head->next == NULL){

        *front = head; // &a
        *back = NULL; // &b

    }else{

        slow = head;
        fast = head->next;

        while(fast != NULL){

            fast = fast->next;

            if(fast != NULL){

                slow = slow->next;
                fast = fast->next;

            }

        }

        *front = head; // a
        *back = slow->next; // b
        slow->next = NULL;
        printList(*front);
        printList(*back);

    }

}

struct node * mergeLists(struct node * a, struct node * b){

    struct node * mergedList = NULL;

    if (a == NULL){
        return b;
    }else if (b == NULL){
        return a;
    }

    if (a->val <= b->val	){
        mergedList = a;
        mergedList->next = mergeLists(a->next, b);
    }else{
        mergedList = b;
        mergedList->next = mergeLists(a, b->next);
    }

    return mergedList;

}

void mergeSort(struct node**source){

    struct node * head = *source;
    struct node * a = NULL;
    struct node * b = NULL;

    if(head == NULL || head->next == NULL){

        return;

    }

    partition(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *source = mergeLists(a, b);

}





int main()

{

		head = (struct node*) malloc(sizeof(struct node));
		head->val = -1;
		head->next = NULL;
		head->prev = NULL;
		cur=head;
		size=0;

		int q;

		scanf("%d", &q);

	

		while(q--)
		{

			char cmd[20];

			scanf("%s", cmd);

			if(strcmp(cmd, "INSERTBEG")==0)
			{
				int v;

				scanf("%d", &v);

				insrtstart(v);
				size++;
			}

			else if(strcmp(cmd, "INSERTEND")==0)
			{
				int v;

				scanf("%d", &v);

				insrtend(v);
				size++;
			}

			else if(strcmp(cmd, "PRINT")==0)
			{
				display();
				printf("\n");
			}

			else if(strcmp(cmd, "DELETENEXT")==0)
			{
				int i,m;

				scanf("%d %d", &i, &m);

				deletenext(i,m);


			}

			else if(strcmp(cmd, "SORT")==0)
			{
				/*int o,l,u;

				scanf("%d %d %d", &o, &l, &u);

				if(o==1)
				{
					sortascnd(l,u);
				}

				else if(o==2)
				{
					sortdscnd(l,u);
				}*/

				int o,l,u;

				scanf("%d %d %d", &o, &l, &u);

                if(o==1)
                {

				    mergesort(&head);
                }

                else if(o==2)
                {
                    mergesort(&head);
                }

			}



		}

return 0;



}