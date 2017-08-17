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


void circular(node **root)
{
	node *temp = *root;

	while(temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = *root;

}

void findLoopInCircularList(node *first)
{
	node *slow = first;
	node *fast = first;

	if(fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
	}


	while(slow != NULL && fast != NULL && fast->next != NULL)
	{
		cout<<"slow "<<slow->value<<" fast "<<fast->value<<"\n";

		slow = slow->next;
		fast = fast->next->next;

		if(slow == fast)
		{
			cout<<"loop node is "<<slow->next->value<<"\n";
			return;
		}

	}

	cout<<"loop not found";
	return;
}

int main(){

  node *root = NULL;

  addNode(&(root), 7);
  addNode(&(root), 5);
  addNode(&(root), 9);
  addNode(&(root), 4);
  addNode(&(root), 6);

  circular(&(root));

  findLoopInCircularList(root);

  return 0;
}
