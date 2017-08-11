#include <iostream>
using namespace std;

struct node
{
  int val;
  node *next;
};

void Addnode(node **root, int value)
{
  if(*root == NULL)
  {
    node *newnode = new node;
    newnode->val = value;
    newnode->next = NULL;
    *root = newnode;
  }
  else
  {
    node *begin = *root;

    while(begin->next != NULL)
    {
      begin = begin->next;
    }

    node *newnode = new node;
    newnode->val = value;
    newnode->next = NULL;
    begin->next = newnode;

  }

}

void Print(node *root)
{
  while(root != NULL)
  {
    cout<<"->"<<root->val;
    root = root->next;
  }
  cout<<"\n";
}

void removeDuplicates(node **root)
{
  if(*root == NULL)
  {
    return;
  }

  node *slow = *root;

  while(slow != NULL)
  {
    node *fast = slow;

    while(fast->next != NULL)
    {
      if(fast->next->val == slow->val)
      {
        node *temp = fast->next;
        fast->next = fast->next->next;
        delete temp;
      }
      else
      {
        fast = fast->next;
      }
    }
    slow = slow->next;
  }

}

void removeDuplicatesUsingHashtable(node **root)
{
  int hashtable[10] = {0};

  if(*root == NULL)
  {
    return;
  }
  node *slow = *root;

  if(slow != NULL)
  {
    hashtable[slow->val] = 1;
  }

  while(slow->next != NULL)
  {
    if(hashtable[slow->next->val] == 1)
    {
      node *temp = slow->next;
      slow->next = slow->next->next;
      delete temp;
    }
    else{
      hashtable[slow->next->val] = 1;
    }

    slow = slow->next;
  }
}

int main()
{
  node *root = NULL;
  Addnode(&root, 2);
  Addnode(&root, 4);
  Addnode(&root, 6);
  Addnode(&root, 2);
  Addnode(&root, 2);
  Addnode(&root, 4);
  Addnode(&root, 3);

  Print(root);

  removeDuplicates(&root);
  Print(root);

  removeDuplicatesUsingHashtable(&root);
  Print(root);

  return 0;
}
