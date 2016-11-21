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

/*bool search(struct node* root,int data)
{
	if(root==NULL)
	{
		return false;
	}

	else if(root->data=data)
	{
		return true;
	}

	else if(data <= root->data)
	{
		return search(root->left,data);
	}

	else
	{
		return search(root->right,data);
	}
}*/

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

int countl(struct node* root)
{
	if(root==NULL)
	{
		return 0;
	}

	else if(root->left==NULL && root->right==NULL)
	{
		return 1;
	}

	else
	{
		return countl(root->left) + countl(root->right);
	}
}

void Preorder(struct node *root)
{
        if(root==NULL)
        {
                return;
        }
        printf("%d ",root->data);
        Preorder(root->left);
        Preorder(root->right);
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
        postrder(root->right);
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

	return findmin(root->left)
	

	
	/*while(root->left!=NULL)
	{
		root=root->left;
	}

	return root->data;*/



}


int findmax(struct node* root)
{
	if(root==NULL)
	{
		return -1;
	}

	/*recursively

	else if(root->right==NULL)
	{
		return root->data;
	}

	return findmin(root->right)
	*/
	
	while(root->right!=NULL)
	{
		root=root->right;
	}

	return root->data;
}



int findheight(struct node* root)
{
	int rl,rr;

	if(root==NULL)
	{
		return -1;
	}

	
	{
		rl=findheight(root->left);
		rr=findheight(root->right);
		return max(rl,rr)+1;
	}
}

/*void LevelOrder(Node *root) {
	if(root == NULL) return;
	queue<Node*> Q;
	Q.push(root);  
	//while there is at least one discovered node
	while(!Q.empty()) {
		Node* current = Q.front();
		Q.pop(); // removing the element at front
		cout<<current->data<<" ";
		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
	}
}*/

int isbstutil(struct node* root, int minvalue, int maxvalue)
{
	if(root==NULL)
	{
		return 1;
	}

	if(root->data > minvalue && root->data < maxvalue && 
		isbstutil(root->left, minvalue, root->data) &&
		isbstutil(root->right, root->data, maxvalue) )
	{
		return 1;
	}

	else
	{
		return 0;
	}

}

int isbst(struct node* root)
{
	return isbstutil(root, INT_MIN, INT_MAX);
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
		root->right = delete(root->right, data)
	}

	else
	{
		if(root->left==NULL && root->right==NULL)
		{
			free root;
			root = NULL;
			//return root;
		}

		else if(root->left==NULL)
		{
			struct node* temp = root;
			root=root->right;
			free temp;
			//return root;
		}

		else if(root->right==NULL)
		{
			struct node* temp = root;
			root=root->left;
			free temp;
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

int main()
{
	int t;

	scanf("%d", &t);

	while(t--)
	{
		struct node* root = NULL;

		int n,i;

		scanf("%d", &n);

		int val;

		for(i=0;i<n;i++)
		{
			scanf("%d", &val );

			root = insert(root,val);
		}

		printf("%d\n", countl(root) );
		Preorder(root);
		printf("\n");
	}

	return 0;
}