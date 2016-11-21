#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int val;
	struct node * next;
}node;

node * insert(node *,int);
int find;
int bfs(node *);
int visited[100010];
node * parent[100010];
void dfs(int);
int dfsVisit(node *);
// 0 is white, 1 is gray, 2 is black
node ** r;
int ctr2;

int main(){
	int n,m,i,t;
	scanf("%d",&t);
	while (t--){
		scanf("%d %d",&n,&m);
		node *cur[n+1];
		node *root[n+1];
		r = root;
		for (i=1;i<=n;i++){
			root[i] = (node *) malloc(sizeof(node));
			root[i]->val = i;
			cur[i] = root[i];
			visited[i]=0; // Mark all as unvisited
			parent[i]=NULL; // Initialized as NULL 
		}
		int a,b;
		while(m--){
			scanf("%d %d",&a,&b);
			cur[a] = insert(cur[a],b);
			cur[b] = insert(cur[b],a);
		}
		ctr2=0;
		dfs(n);

	}
}


node * insert(node * cur,int value){
	node * newNode = (node *) malloc(sizeof(node));
	cur->next = newNode;
	newNode->next = NULL;
	newNode->val = value;
	return newNode;
}

void dfs(int size){
	int i;
	int flag = 1;
	flag = dfsVisit(r[1]);
	if (flag==0){
		printf("NO\n");
		return;
	}
	for(i=1;i<=size;i++){
		if (visited[i]!=2){
			flag = 0;
			break;
		}
	}
	if (flag){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
}

int dfsVisit(node * x){
	ctr2++;
	if (ctr2>1000000){
		printf("END\n");
		return 0;
	}
	visited[x->val] = 1;
	node * y = x;
	int ctr=0;
	while (y->next!=NULL){
		ctr++;
		if (ctr>1000000){
			printf("END\n");
			return 0;
		}
		y = y->next;
		if (visited[y->val]==0){
			parent[y->val]=x;
			dfsVisit(r[y->val]);
		}
		else if (!(visited[y->val]==1 && parent[x->val]==r[y->val])){
			return 0;
		}
	}
	visited[x->val] = 2;
	return 1;
}