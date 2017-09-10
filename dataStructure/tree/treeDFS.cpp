#include<iostream>
#include<queue>
using namespace std;

struct node
{
	int val;
	node *left;
	node *right;
};

void Addnode(node **root, int data)
{
	if(*root == NULL)
	{
		node *newnode = new node;
		newnode->val = data;
		newnode->left = NULL;
		newnode->right = NULL;
		*root = newnode;
	}
	else
	{
		if(data <= ((*root)->val))
		{
			Addnode(&((*root)->left), data);
		}
		else
		{
			Addnode(&((*root)->right), data);
		}

	}
}

queue<node*> myQueue;

void BFS(node *root)
{
	if(root == NULL) return;

	node *temp = root;

	myQueue.push(temp);

	while(!myQueue.empty())
	{
		node *ex = myQueue.front();
		cout<<ex->val<<" ";
		myQueue.pop();

		if(ex->left != NULL)
		{
			node *left = ex->left;
			myQueue.push(left);
		}

		if(ex->right != NULL)
		{
			node *right = ex->right;
			myQueue.push(right);
		}

	}


}

int main()
{
	node *root = NULL;
	Addnode(&root,20);
	Addnode(&root,15);
	Addnode(&root,10);
	Addnode(&root,18);
	Addnode(&root,25);
	Addnode(&root,30);

  cout<<"BFS :- ";
	BFS(root);

	cout<<endl;

 	return 0;
}
