#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node 
{
	int data;
	struct node* left;
	struct node* right;
};

//struct node* root;
//struct node* cur;

struct node* getnewnode(int data)
{
	struct node* newnode = (struct node*) malloc (sizeof(struct node));

	newnode->data = data;
	newnode->right = NULL;
	newnode->left = NULL;
	return newnode;
}



struct node* insert(struct node* root,int data)
{
	if(root==NULL)
	{
		root=getnewnode(data);
	}

	else if(data <= root->data)
	{
		root->left = insert(root->left,data);
	}

	else
	{
		root->right = insert(root->right,data);
	}

	return root;

}



void preorder(struct node *root)
{
        if(root==NULL)
        {
         	return;
        }
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
}

void inorder(struct node* root)
{
	 if(root==NULL)
        {
             return;
        }
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
}

void postorder(struct node* root)
{
	 if(root==NULL)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
}



/*
int findmin(struct node* root)
{
	if(root==NULL)
	{
		return -1;
	}
	
	//recursively

	//else if(root->left==NULL)
	//{
	//	return root->data;
	//}

	//return findmin(root->left)
	

	
	while(root->left!=NULL)
	{
		root=root->left;
	}

	return root->data;

}
*/

struct node* findmin(struct node* root)
{
	if(root==NULL)
	{
		return root;
	}
	
	
	else if(root->left==NULL)
	{
		return root;
	}

	return findmin(root->left);
	

	
	/*while(root->left!=NULL)
	{
		root=root->left;
	}

	return root->data;*/



}




struct node* delete(struct node* root, int data)
{
	if(root==NULL)
	{
		return root;
	}

	else if(data < root->data)
	{
		root->left = delete(root->left, data);
	}

	else if(data > root->data)
	{
		root->right = delete(root->right, data);
	}

	else
	{
		if(root->left==NULL && root->right==NULL)
		{
			free(root);
			root = NULL;
			//return root;
		}

		else if(root->left==NULL)
		{
			struct node* temp = root;
			root=root->right;
			free(temp);
			//return root;
		}

		else if(root->right==NULL)
		{
			struct node* temp = root;
			root=root->left;
			free(temp);
			//return root;
		}

		else
		{
			struct node* temp = findmin(root->right);
			root->data = temp->data;
			root->right = delete(root->right, temp->data);
		}	
	}

	return root;
}

void postorderd(struct node* root, struct node** temp, int i, int u)
{
	 if(root==NULL)
        {
            return;
        }
        postorderd(root->left,temp,i,u);
        postorderd(root->right,temp,i,u);
        //printf("%d ",root->data);
        if((root->data > i) && (root->data < u))
        {
        	*temp=delete(*temp,root->data);
        }
}

int main()
{
	char cmd[10]={};
	int val,k;
	int i,u;

	struct node* root = NULL;

	while(strcmp(cmd, "END")!=0)
	{
		

		scanf("%s", cmd);

		if(strcmp(cmd, "INSERT")==0)
		{
			scanf("%d", &val);

			root = insert(root, val);
		}

		else if(strcmp(cmd, "DELETE")==0)
		{
			
			scanf("%d %d", &i, &u);

			postorderd(root,&root,i,u);
		}

		else if(strcmp(cmd, "PRINT")==0)
		{
			scanf("%d", &k);

			if(k==1)
			{
				inorder(root);
				printf("\n");
			}

			else if(k==2)
			{
				preorder(root);
				printf("\n");
			
			}

			else if(k==3)
			{
				postorder(root);
				printf("\n");
			
			}

		}
	}
	return 0;
}