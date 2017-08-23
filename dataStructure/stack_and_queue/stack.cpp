#include <iostream>
using namespace std;

struct node
{
	int val;
	node *next;
};

//empty stack
node *stack = NULL;
node *start = NULL;
node *last = NULL;

//empty minstack
node *minstack = NULL;
node *minstart = NULL;
node *minlast = NULL;

void Push(int value)
{
	node *newnode = new node;
	newnode->val = value;
	newnode->next = NULL;

	if(stack == NULL)
	{
		stack = newnode;
		start = newnode;
	  last = newnode;
	}
	else
	{
		newnode->next = last;
    last = newnode;
    stack = newnode;
	}

	//push values into min stack
	if(minstack == NULL)
	{
		node *newnode = new node;
		newnode->val = value;
		newnode->next = NULL;

		minstack = newnode;
		minstart = newnode;
	  minlast = newnode;
	}
	else
	{
		node *newnode = new node;

		if(value < minlast->val)
		{
			newnode->val = value;
		}
		else
		{
			newnode->val = minlast->val;
		}
		newnode->next = minlast;
		minlast = newnode;
    minstack = newnode;
	}

}
int Pop()
{

	if(last == NULL)
	{
		cout<<"Nothing to pop";
		return 0;
	}
	else
	{
    node *temp = last;
		int popvalue = last->val;
		last = last->next;
		stack = last;
		delete temp;

		//pop minstack top
		node *temp1 = minlast;
		minlast = minlast->next;
		minstack = minlast;
		delete temp1;

		return popvalue;
	}
}

int getMin()
{
	return minlast->val;
}

void Print(node *stack)
{
	node *front = stack;

	while(front != NULL)
	{
		cout<<"->"<<front->val;
		front = front->next;
	}
	cout<<endl;
}
int main()
{
	int popedvalue;
	int minval;
	Push(3);
	Push(7);
	Push(2);
	Push(9);
	Print(stack);
	Print(minstack);
	minval = getMin();
	cout<<minval<<"\n";

	popedvalue = Pop();
	popedvalue = Pop();
	Print(stack);
	minval = getMin();
	cout<<minval<<"\n";

	return 0;
}
