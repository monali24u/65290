#include <iostream>
using namespace std;

struct node
{
  char value;
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

void reverseList(node **head)
{
	node *prev = NULL;
	node *current = *head;
	node *temp;

	while(current != NULL)
	{
		temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
	}

	*head = prev;
}

bool compareList(node *first, node *second)
{
	node *one = first;
	node *two = second;

	while(one != NULL && two != NULL)
	{
		if(one->value == two->value)
		{
			one = one->next;
			two = two->next;
		}
		else
		{
			return 0;
		}
	}

	if(one == NULL && two == NULL)
	{
		return 1;
	}

	return 0;
}

bool linkedListIsPalindrome(node *first)
{

	node *slow = first;
	node *fast = first;
	node *prev = first;
	node *mid = NULL;
	bool result = true;

	if (first != NULL && first->next != NULL)
    {
		//find middle node,
		while(fast != NULL && fast->next != NULL)
		{
			fast = fast->next->next;
			prev = slow;
			slow = slow->next;
		}

		//if list length is odd move middle node;
		if(fast != NULL)
		{
			mid = slow;
			slow = slow->next;
		}

		//reverse second half of list
		reverseList(&slow);
		prev->next = NULL;
		result = compareList(first, slow);

		//construct original linkedlist
		reverseList(&slow);

		if(mid != NULL)
		{
			prev->next = mid;
			mid->next = slow;
		}
		else
		{
			prev->next = slow;
		}
	}

	return result;

}

int main(){

  node *root = NULL;

  addNode(&(root), 'A');
  addNode(&(root), 'B');
  addNode(&(root), 'C');
  addNode(&(root), 'B');
  addNode(&(root), 'A');

  print(root);

  bool res = linkedListIsPalindrome(root);

  if(res == true)
  {
	cout<<"Is Palindrome"<<"\n";
  }
  else
  {
	cout<<"not Palindrome"<<"\n";
  }

  return 0;
}
