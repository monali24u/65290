#include<iostream>
#include<array>
using namespace std;

struct node
{
  int val;
  node *left;
  node *right;
};

node * createNode(int data)
{
  node *newnode = new node;
  newnode->val = data;
  newnode->left = NULL;
  newnode->right = NULL;

  return newnode;
}

node * createBST(int A[], int start, int end)
{
  if(start > end)
    return NULL;

  int mid = (start + end)/2;
  node *root = createNode(A[mid]);

  root->left = createBST(A, start, mid-1);
  root->right = createBST(A,mid+1, end);

  return root;
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
  int array[] = {2,3,4,6,8,9,10,12,15};
  int start = 0;
  int end = sizeof(array)/sizeof(array[0]) - 1;

  node *result = createBST(array, start, end);

  Preorder(result);
  cout<<endl;

  return 0;
}
