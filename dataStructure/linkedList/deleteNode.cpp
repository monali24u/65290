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

void deleteNode(node *given)
{
	if(given == NULL)
	{
		cout<<"empty list. Nothing to delete.\n";
	}
	else
	{
		if(given->next != NULL)
		{
			node *temp = given->next;
			given->value = given->next->value;
			given->next = given->next->next;
			delete temp;
		}
		else
		{
			delete given;
		}
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

  int i=1;
  int n=3;

  node *begin = root;

  if(begin != NULL)
	{
		while(i < n)
		{
			if(begin->next != NULL)
			{
				begin = begin->next;
				i++;
			}
		}
	}

  deleteNode(begin);
  print(root);

  return 0;
}
