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


int HeightofBST(node *root)
{
	if(root == NULL)
		return 0;

	int leftheight = 1 + HeightofBST(root->left);
	int rightheight = 1 + HeightofBST(root->right);

	if(leftheight < rightheight)
		return rightheight;
	else
		return leftheight;

}

bool IsBalanced(node *root)
{
	if(root == NULL)
		return true;

	if(root->left == NULL && root->right == NULL)
		return true;

	int leftheight = HeightofBST(root->left);
	int rightheight = HeightofBST(root->right);

	int diff = leftheight - rightheight;
	if(diff < 0) diff = rightheight - leftheight;

	if(diff > 1)
		return false;
	else
		return IsBalanced(root->left) && IsBalanced(root->right);
}

//efficient solution
int EffHeightofBST(node *root)
{
	if(root == NULL)
		return 0;

	int leftheight = 1 + EffHeightofBST(root->left);
	int rightheight = 1 + EffHeightofBST(root->right);

	int diff = leftheight - rightheight;
	if(diff < 0) diff = rightheight - leftheight;

	if(diff > 1)
	{
		return -1;
	}
	else
	{
		if(leftheight < rightheight)
			return rightheight;
		else
			return leftheight;
	}
}

bool EffIsBalanced(node *root)
{
	if(root == NULL)
		return true;

	if(root->left == NULL && root->right == NULL)
		return true;

	int leftheight = EffHeightofBST(root->left);
	int rightheight = EffHeightofBST(root->right);
	cout<<"leftheight "<<leftheight<<"\n";
	cout<<"rightheight "<<rightheight<<"\n";

	if(leftheight == -1 || rightheight == -1)
	{
		return false;
	}

	return true;
}


int main()
{
	node *root = NULL;
	Addnode(&root,12);
	Addnode(&root,7);
	Addnode(&root,3);
	Addnode(&root,9);
	Addnode(&root,2);
	Addnode(&root,5);
	Addnode(&root,11);
	Addnode(&root,15);
	Addnode(&root,13);
	Addnode(&root,20);
	Addnode(&root,22);
	//Addnode(&root,24);

  cout<<"Inorder :- ";
	Inorder(root);
	cout<<"\n";

	bool result = EffIsBalanced(root);
	if(result == true)
	{
		cout<<"tree is balanced.\n";
	}
	else
	{
		cout<<"tree is not balanced.\n";
	}

}
