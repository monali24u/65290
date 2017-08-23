#include<iostream>
#include<climits>
using namespace std;

struct node
{
	int val;
	node *left;
	node *right;
};

//global
int cnt = 1;
node *tochange = NULL;

void Addnode(node **root, int data)
{

	if(*root == NULL)
	{
		node *newnode = new node;
		newnode->val = data;
		newnode->left = NULL;
		newnode->right = NULL;
		*root = newnode;
		if(cnt == 5)
		{
			tochange = *root;
		}

		cnt++;
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

bool isBST(node *root, int min, int max)
{
	if(root == NULL)
	return true;

	if(root->left == NULL && root->right == NULL)
	return true;

	if(root->left != NULL)
	{
		if(root->left->val < min || root->left->val > root->val)
			return false;
	}
	if(root->right != NULL)
	{
		if(root->right->val > max || root->right->val < root->val)
			return false;
	}

	bool LT = isBST(root->left, min, root->val);
	bool RT = isBST(root->right, root->val, max);

	return (LT && RT);
}

int main()
{
	node *root = NULL;
	Addnode(&root,10);
	Addnode(&root,5);
	Addnode(&root,20);
	Addnode(&root,3);
	Addnode(&root,9);
	Addnode(&root,15);
	Addnode(&root,25);

	Inorder(root);
	//tochange->val = 12;
  //Inorder(root);

	bool result = isBST(root,INT_MIN,INT_MAX);

	if(result == true)
	{
		cout<<"tree is BST.\n";
	}
	else
	{
		cout<<"tree is not BST.\n";
	}

 	return 0;
}
