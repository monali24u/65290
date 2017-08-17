
#include <iostream>
using namespace std;

struct node
{
  int value;
  node *next;
};

void addNode(node **root, int val, node **end)
{
  if(*root == NULL)
  {
    node *newnode = new node;
    newnode->value = val;
    newnode->next = NULL;
    *root = newnode;
    *end = newnode;
  }
  else
  {
      node *newnode = new node;
      newnode->value = val;
      newnode->next = NULL;
      (*end)->next = newnode;
      *end = newnode;
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

node* moveNodeLessThanXToLeft(node *root, int x)
{
    node *left = NULL;
    node *leftEnd = NULL;
    node *right = NULL;
    node *rightEnd = NULL;

    while(root != NULL)
    {
      if((root->value) < x)
      {
        addNode(&(left), root->value, &(leftEnd));
      }
      else
      {
        addNode(&(right), root->value, &(rightEnd));
      }
      root = root->next;
    }

    leftEnd->next = right;
    return left;
}

int main(){

  node *root = NULL;
  node *end = NULL;

  addNode(&(root), 10, &(end));
  addNode(&(root), 12, &(end));
  addNode(&(root), 8, &(end));
  addNode(&(root), 5, &(end));
  addNode(&(root), 1, &(end));
  addNode(&(root), 9, &(end));
  print(root);

  node *result = moveNodeLessThanXToLeft(root, 6);
  print(result);

  return 0;
}
