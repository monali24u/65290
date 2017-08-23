#include<iostream>
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

void Inorder(node *root)
{
	if(root != NULL)
	{
		Inorder(root->left);

		cout<<root->val<<" ";

		Inorder(root->right);
	}
}

void Postorder(node *root)
{
	if(root != NULL)
	{
		Postorder(root->left);

		Postorder(root->right);

		cout<<root->val<<" ";

	}
}

void Preorder(node *root)
{
	if(root != NULL)
	{
		cout<<root->val<<" ";

		Preorder(root->left);

		Preorder(root->right);
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

  cout<<"Inorder :- ";
	Inorder(root);

	cout<<"Postorder :- ";
	Postorder(root);

	cout<<"Preorder :- ";
	Preorder(root);
	cout<<endl;

 	return 0;
}
