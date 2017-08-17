#include <iostream>
using namespace std;

struct node
{
  int value;
  node *next;
};

void addNode(node **root, int val)
{
  if(*root == NULL)
  {
    node *newnode = new node;
    newnode->value = val;
    newnode->next = NULL;
    *root = newnode;
  }
  else
  {
      node *begin = *root;

      while(begin->next != NULL){
        begin = begin->next;
      }

      node *newnode = new node;
      newnode->value = val;
      newnode->next = NULL;
      begin->next = newnode;

  }

}

void print(node *root)
{
  while(root != NULL)
	 {
		cout<<"->"<<(root)->value;
	 	root = (root)->next;
	 }
   cout<<"\n";
}

void findNthNodeFromLast(node *root, int n)
{
	node *slow = root;
	node *fast = root;
	int i=1;

	if(n == 0)
	{
		cout<<"Invalid value";
		return;
	}

	if(root != NULL)
	{
		while(i < n)
		{
			if(fast->next != NULL)
			{
				fast = fast->next;
				i++;
			}
			else
			{
				cout<<n<<"th value is greater than linkedlist."<<"\n";
				return;
			}
		}

		while(fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}

		cout<<n<<"th node from last is "<<slow->value<<"\n";

	}

}

int main(){

  node *root = NULL;

  addNode(&(root), 2);
  addNode(&(root), 4);
  addNode(&(root), 6);
  addNode(&(root), 3);
  addNode(&(root), 9);
  addNode(&(root), 1);

  print(root);

  findNthNodeFromLast(root, 2);

  return 0;
}
