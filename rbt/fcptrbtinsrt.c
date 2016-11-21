#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node 
{
	int data;
	int color;
	struct node* left;
	struct node* right;
	struct node* parent;
};

struct node* nil;
struct node* root;

struct node* getnewnode(struct node* p, int data)
{
	struct node* newnode = (struct node*) malloc (sizeof(struct node));

	newnode->parent = p;
	newnode->data = data;
	newnode->right = nil;
	newnode->left = nil;
	newnode->color = 1;
	return newnode;
}

void left_rotate(struct node* x) 
{
    struct node* y = x->right;
    
    x->right = y->left;
    
    if ( y->left != nil )
    {
        y->left->parent = x;
    }
    
    y->parent = x->parent;
   
    if ( x->parent == nil )
    {
    	root = y;
    } 
    
    else if ( x == x->parent->left )
    {
        x->parent->left = y;
    }
        
    else
    {
    	x->parent->right = y;
    }
  	y->left = x;
    x->parent = y;
    
            
           
}

void right_rotate(struct node* x) 
{
    struct node* y = x->left;
    
    x->left = y->right;
    
    if ( y->right != nil )
    {
        y->right->parent = x;
    }
    
    y->parent = x->parent;
   
    if ( x->parent == nil )
    {
    	root = y;
    } 
    
    else if ( x == x->parent->right )
    {
        x->parent->right = y;
    }
        
    else
    {
    	x->parent->left = y;
    }
 	y->right = x;
   	x->parent = y;

            
           
}


void RBT_fix(struct node* n)
{
	while(n->parent->color == 1)
	{
		if(n->parent == n->parent->parent->left)
		{
			struct node* z = n->parent->parent->right;

			if(z->color == 1)
			{
				z->color = 0;
				n->parent->color = 0;
				n->parent->parent->color = 1;
				n = n->parent->parent; 
			}

			else
			{
				if(n == n->parent->right)
				{
					n= n->parent;
					left_rotate(n);
				}

				n->parent->color = 0;
				n->parent->parent->color = 1;
				right_rotate(n->parent->parent);
			}
		}

		else
		{
			struct node* z = n->parent->parent->left;

			if(z->color == 1)
			{
				z->color = 0;
				n->parent->color = 0;
				n->parent->parent->color = 1;
				n = n->parent->parent; 
			}

			else
			{
				if(n == n->parent->left)
				{
					n= n->parent;
					right_rotate(n);
				}

				n->parent->color = 0;
				n->parent->parent->color = 1;
				left_rotate(n->parent->parent);
			}
		}
	}

	root->color = 0;
}


struct node* insert(int data)
{
	struct node* cur = root;
	struct node* p = nil;

	while(cur!=nil)
	{
		p = cur;

		if(data < cur->data)
		{
			cur = cur->left;
		}

		else
		{
			cur = cur->right;
		}
	}
	cur = getnewnode(p,data);

	if(p==nil)
	{
		root = cur;
	}
	else if(cur->data < p->data)
	{
		p->left = cur;
	}

	else
	{
		p->right = cur;
	}

		RBT_fix(cur);
	


}


void lvlordr(int num)
{
	int start, end;

	struct node* a[5000];

	int c=0;

	start=0;
	end=0;

	struct node* cur=root;

	if(cur!=nil)
	{
		a[end++]=cur;
		
	}

	while(start<end)
	{
		struct node* b = a[start++];

		if(b->color==num)
		{
			printf("%d ", b->data);
			c=1;
		}

		if(b->left!=nil)
		{
			a[end++]=b->left;
		}

		if(b->right!=nil)
		{
			a[end++]=b->right;
		}
	}

	if(c==1)
	{
		printf("\n");
	}
}
void inorder(struct node* root)
{
	if(root != nil)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}
int main()
{
	int q;

	scanf("%d", &q);
		nil = (struct node*) malloc (sizeof(struct node));
		nil->data = 999;
		nil->color = 0;
		nil->left = nil;
		nil->right = nil;
		nil->parent = nil;
		root = nil;

	while(q--)
	{
		char cmd[10];

		scanf("%s", cmd);

		if(strcmp(cmd, "INSERT")==0)
		{
			int v;

			scanf("%d", &v);

			insert(v);
		//	inorder(root);
	


		}

		else 
		{
			char c;

			scanf(" %c", &c);

			if( c== 'R')
			{
				lvlordr(1);
				//printLevelOrder(root,1);
				printf("\n");
			}

			if(c=='B')
			{
				lvlordr(0);
				//printLevelOrder(root,0);
				printf("\n");
			}

		}
	}	
}