#include<iostream>
#include<vector>
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


void countPathsWithGivenSum(node *root, int level, vector<int> &vec, int &count, int inputSum)
{
	if(root == NULL) return;

	if(vec.size() > level)
	{
		vec[level] = root->val;
	}
	else
	{
		vec.push_back(root->val);
	}

	int sum = 0;

	for(int i=level; i>=0; i--)
	{
			sum = sum + vec[i];
			if(sum == inputSum)
			{
				count = count + 1;
			}
	}

countPathsWithGivenSum(root->left,level+1, vec, count, inputSum);
countPathsWithGivenSum(root->right,level+1, vec, count, inputSum);

}


int main()
{
	node *root = NULL;
	Addnode(&root,2);
	Addnode(&root,1);
	Addnode(&root,3);
	Addnode(&root,4);
	Addnode(&root,3);
	Addnode(&root,-2);
	Addnode(&root,2);

	vector<int> vec;
	int level = 0;
	int count = 0;
	int sum = 5;
	countPathsWithGivenSum(root, level, vec, count, sum);
	cout<<count<<endl;

 	return 0;
}
