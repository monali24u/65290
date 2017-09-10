#include<iostream>
#include<vector>
using namespace std;

struct node
{
	int val;
	node *left;
	node *right;
};

struct list
{
	int val;
	list* next;
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


void createLinkedlist(node *root, int level, vector<list*> &vec)
{
	if(root == NULL) return;

	if(level == vec.size())
	{
		//first node of the tree level.
		list *newlist = new list;
    newlist->val = root->val;
    newlist->next = NULL;
    vec.push_back(newlist);
	}
	else
	{
		//its not first node. traverse the list and add it at end of list.
		list *temp = vec[level];

		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		list *newlist = new list;
    newlist->val = root->val;
    newlist->next = NULL;
		temp->next = newlist;

	}
	createLinkedlist(root->left, level+1, vec);
	createLinkedlist(root->right, level+1, vec);
}

void printVec(vector<list*> vec)
{
	for (vector<list*>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		list *newlist = *it;
		while(newlist != NULL)
		 {
			cout<<"->"<<(newlist)->val;
		 	newlist = (newlist)->next;
		 }
   	 cout<<"\n";
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

  //cout<<"Inorder :- ";
	//Inorder(root);

	vector<list*> vec;
	int level = 0;

	createLinkedlist(root, level, vec);
	printVec(vec);

 	return 0;
}
