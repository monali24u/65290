#include<iostream>
#include<vector>
using namespace std;

struct node
{
	int val;
	node *left;
	node *right;
};


void printVec(vector<int> vec, int level)
{
	for(vector<int>::iterator it = vec.begin(); it <= vec.begin()+level; it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}

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

bool givenRootAndNodeFindPath(node *root, vector<int> &vec, int endPoint, int level)
{
	if(root == NULL) return false;

	if(root->val == endPoint)
	{
		if(level == vec.size())
		{
			vec.push_back(root->val);
		}
		else
		{
			vec[level] = root->val;
		}
    printVec(vec, level);
		return true;
	}

	if(level == vec.size())
	{
		vec.push_back(root->val);
	}
	else
	{
		vec[level] = root->val;
	}
	bool foundleft = givenRootAndNodeFindPath(root->left, vec, endPoint,level+1);
	bool foundright = givenRootAndNodeFindPath(root->right, vec, endPoint, level+1);

	return (foundleft || foundright);
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

	vector<int> vec;
	bool result = givenRootAndNodeFindPath(root, vec, 19,0);

	if(result == false)
	{
		cout<<"Either Root is Empty or Path not found."<<endl;
	}

 	return 0;
}
