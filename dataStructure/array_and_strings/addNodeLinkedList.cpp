#include <iostream>
using namespace std;


struct node
{
	int value;
	node *nextnode;
};

void AddNode(node **root, int value)
{
	if(*root == NULL)
	{
		node *newnode = new node;
		newnode->value = value;
		newnode->nextnode = NULL;
		*root = newnode;

	}
	else
	{
		node *begin = *root;

		while(begin->nextnode != NULL)
		begin = begin->nextnode;

		node *newnode = new node;
		newnode->value = value;
		newnode->nextnode = NULL;
		begin->nextnode = newnode;

	}
}
void Addafter(node **root2,int value1, int value2)
{
	node *start = *root2;
	node *temp1 = new node;
	temp1->value = value2;
	temp1->nextnode = NULL;

	while(start != NULL)
	{
		if(start->value == value1)
		{
			temp1->nextnode = start->nextnode;
			start->nextnode = temp1;
		}

	  start = start->nextnode;
	}

}

void Addbefore(node **root3,int value1, int value2)
{
	node *tempprevious = *root3;
	node *tempnext = tempprevious->nextnode;

	node *temp2 = new node;
	temp2->value = value2;
	temp2->nextnode = NULL;

	while(tempnext != NULL)
	{
		if(tempnext->value == value1)
		{
			temp2->nextnode = tempnext;
			tempprevious->nextnode = temp2;
		}

	  tempprevious = tempprevious->nextnode;
	  tempnext =tempnext->nextnode;
	}

}

void Addbetween(node **root4, int value1, int value2,int value3)
{
	node *tempprevious1 = *root4;
	node *tempnext1 = tempprevious1->nextnode;

	node *temp3 = new node;
	temp3->value = value3;
	temp3->nextnode = NULL;

	while(tempnext1 != NULL)
	{
		if(tempnext1->value == value2 && tempprevious1->value == value1)
		{
			temp3->nextnode = tempnext1;
			tempprevious1->nextnode = temp3;
		}

	 tempprevious1 = tempprevious1->nextnode;
	 tempnext1 =tempnext1->nextnode;
	}

}


void Print(node **root1)
{
	node *root = *root1;
	while(root != NULL)
	 {
		cout<<"->"<<(root)->value;
	 	root = (root)->nextnode;
	 }


}
int main()
{
		node *root = NULL;
		AddNode(&(root), 6);
    AddNode(&(root), 3);
    AddNode(&(root), 8);
    AddNode(&(root), 9);
    AddNode(&(root), 5);


  	Addafter(&(root),8,18);
  	Addbefore(&(root),8,18);
  	Addbetween(&(root),8,18,18);

    Print(&(root));

	return 0;
}
