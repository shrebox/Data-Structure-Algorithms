#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	int color; // Black = 0 ; Red = 1;
	struct node *p, *l,*r;
}node;

void leftRotate(node *);
void rightRotate(node *);
void insert(int);
void RBTfix(node *);
void rbDeleteFix(node *);
void delete(int);
node * nil;
node * root;
void rb_print_r(node *,int);

int main(){
	int n;
	nil = (node *) malloc(sizeof(node));
	nil->val = 999;
	nil->color = 0;
	nil->l = nil;
	nil->r = nil;
	nil->p = nil;
	root = nil;
	int x=1;
	while (x<11){
		insert(x);
		x++;
	}
	rb_print_r(root,0);
	x=0;
	while (x<10){
		nil->p = nil;
		nil->color = 0;
		scanf("%d",&n);
		delete(n);
		x++;
		rb_print_r(root,0);
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	}
	
}

void insert(int x){
	node * cur = root;
	node * par = nil;
	while (cur!=nil){
		par = cur;
		if (x<cur->val)
			cur = cur->l;
		else
			cur = cur->r;
		// Equal goes right
	}
	cur = (node *) malloc(sizeof(node));
	cur->p = par;
	cur->l = nil;
	cur->r = nil;
	cur->val = x;
	cur->color = 1; // Red
	if (par==nil)
		root = cur;
	else if (cur->val<par->val)
		par->l = cur;
	else
		par->r = cur;
	if (cur->p!=nil && cur->p->p!=nil){
		RBTfix(cur);
	}
}

void RBTfix(node * n){
	while (n->p->color==1){
		if (n->p == n->p->p->l){
			node * uncle = n->p->p->r;
			if (uncle->color==1){
				uncle->color = 0;
				n->p->color = 0;
				n->p->p->color = 1;
				n = n->p->p;
			}
			else{
				if (n==n->p->r){
					n = n->p;
					leftRotate(n);
				}
				n->p->color = 0;
				n->p->p->color = 1;
				rightRotate(n->p->p);
			}
		}
		else{
			node * uncle = n->p->p->l;
			if (uncle->color==1){
				uncle->color = 0;
				n->p->color = 0;
				n->p->p->color = 1;
				n = n->p->p;
			}
			else{
				if (n==n->p->l){
					n = n->p;
					rightRotate(n);
				}
				n->p->color = 0;
				n->p->p->color = 1;
				leftRotate(n->p->p);
			}	
		}
	}
	root->color = 0;
}

void leftRotate(node * curNode){
	node * rightChild = curNode->r;
	curNode->r = rightChild->l;
	if (rightChild->l!=nil)
		rightChild->l->p = curNode;
	rightChild->p = curNode->p;      
	if (curNode->p == nil){
		root = rightChild;
	}
	else if (curNode == curNode->p->l)
		curNode->p->l = rightChild;
	else
		curNode->p->r = rightChild;
	rightChild->l = curNode;
	curNode->p = rightChild;
}

void rightRotate(node * curNode){
	node * leftChild = curNode->l;
	curNode->l = leftChild->r;
	if (leftChild->r!=nil)
		leftChild->r->p = curNode;
	leftChild->p = curNode->p;      
	if (curNode->p == nil){
		root = leftChild;
	}
	else if (curNode == curNode->p->r)
		curNode->p->r = leftChild;
	else
		curNode->p->l = leftChild;
	leftChild->r = curNode;
	curNode->p = leftChild;
}

void rb_print_r(node * cur, int num)
{
    int i;
    if( cur != nil)
    {
        rb_print_r( cur->r, num+1);
 
        for(i = 0; i < num; i++)
            putchar('\t');
 
        printf("%d %d\n",  cur->val, cur->color); 
        rb_print_r( cur->l, num+1);
    }
    else
    {
        for(i = 0; i < num; i++)
            putchar('\t');
        puts("~");
    }
}

void rbTransplant(node * x, node * y){
	if (x->p==nil)
		root = y;
	else if (x == x->p->l)
		x->p->l = y;
	else
		x->p->r = y;
	y->p = x->p;
}

node * treeMin(node * cur){
	while (cur->l!=nil)
		cur = cur->l;
	return cur;
}

void delete(int n){
	node * cur=root;
	node * nodeDel;
	while (cur!=nil && cur->val!=n){
		if (n<cur->val)
			cur = cur->l;
		else
			cur = cur->r;
	}
	if (cur!=nil){
		nodeDel = cur;
		int origColor = cur->color;
		node * fix;
		if (nodeDel->l==nil){
			fix = nodeDel->r;
			rbTransplant(nodeDel,nodeDel->r);
		}
		else if (nodeDel->r==nil){
			fix = nodeDel->l;
			rbTransplant(nodeDel,nodeDel->l);
		}
		else{
			cur = treeMin(nodeDel->r);	
			origColor = cur->color;
			fix = cur->r;
			if (cur->p==nodeDel)
				fix->p = cur;
			else{
				rbTransplant(cur,cur->r);
				cur->r = nodeDel->r;
				cur->r->p = cur;
			}
			rbTransplant(nodeDel,cur);
			cur->l = nodeDel->l;
			cur->l->p = cur;
			cur->color =nodeDel->color;
		}
		if (origColor==0){
			rbDeleteFix(fix);
		}
	}
}

void rbDeleteFix(node * nodeIn){
	while (nodeIn!=root && nodeIn->color==0){
		if (nodeIn==nodeIn->p->l){
			node * cur = nodeIn->p->r;
			if (cur->color==1){
				cur->color = 0;
				nodeIn->p->color = 1;
				leftRotate(nodeIn->p);
				cur = nodeIn->p->r;
			}
			if (cur->l->color==0 && cur->r->color==0){
				cur->color = 1;
				nodeIn = nodeIn->p;
			}
			else{ 
				if (cur->r->color == 0){
					cur->l->color = 0;
					cur->color = 1;
					rightRotate(cur);
					cur = nodeIn->p->r;				
				}
				cur->color = nodeIn->p->color;
				nodeIn->p->color = 0;
				cur->r->color = 0;
				leftRotate(nodeIn->p);
				nodeIn = root;
			}
		}
		else{
			node * cur = nodeIn->p->l;
			if (cur->color==1){
				cur->color = 0;
				nodeIn->p->color = 1;
				rightRotate(nodeIn->p);
				cur = nodeIn->p->l;
			}
			if (cur->r->color==0 && cur->l->color==0){
				cur->color = 1;
				nodeIn = nodeIn->p;
			}
			else{
				if (cur->l->color == 0){
					cur->r->color = 0;
					cur->color = 1;
					leftRotate(cur);
					cur = nodeIn->p->l;				
				}
				cur->color = nodeIn->p->color;
				nodeIn->p->color = 0;
				cur->l->color = 0;
				rightRotate(nodeIn->p);
				nodeIn = root;
			}
		}
	}
	nodeIn->color=0;
}