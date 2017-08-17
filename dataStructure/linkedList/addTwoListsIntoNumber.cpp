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

node* addTwoLists(node *first, node *second)
{
	node *result = NULL;
	int carry = 0;
	int sum = 0;

	if(first == NULL && second == NULL)
	{
		cout<<"both linkedlist's are empty";
	}

	if(first == NULL && second != NULL)
	{
		return second;
	}

	if(first != NULL && second == NULL)
	{
		return first;
	}

	while(first != NULL || second != NULL)
	{
		sum = (first? first->value:0) + (second? second->value:0) + carry;

		if(sum < 10)
		{
			carry = 0;
		}
		if(sum >= 10 && sum < 20)
		{
			carry = 1;
		}
		if(sum >= 20)
		{
			carry = sum % 10;
		}

		addNode(&(result), sum%10);

		if(first != NULL)
			first = first->next;
		if(second != NULL)
			second = second->next;
	}

	if(carry > 0)
		addNode(&(result), carry);

	return result;
}

int main(){

  node *root = NULL;

  addNode(&(root), 7);
  addNode(&(root), 5);
  addNode(&(root), 9);
  addNode(&(root), 4);
  addNode(&(root), 6);


  print(root);

  node *root1 = NULL;

  addNode(&(root1), 8);
  addNode(&(root1), 4);
  //addNode(&(root1), 2);


  print(root1);

  node *res = NULL;

 res = addTwoLists(root, root1);

  print(res);

  return 0;
}
