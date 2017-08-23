//Given an expression string exp , write a program to examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.

#include<iostream>
#include<string>
#include <stack>
using namespace std;

stack<char> s1;

bool isBalancedOrNot(string str)
{
  for(int i=0; i<str.length(); i++)
  {
    if(str[i]=='(' || str[i]=='[' || str[i]=='{')
    {
      s1.push(str[i]);
    }
    else
    {
      if(s1.top()=='(' && str[i]==')')
      {
        s1.pop();
      }
      else if(s1.top()=='[' && str[i]==']')
      {
        s1.pop();
      }
      else if(s1.top()=='{' && str[i]=='}')
      {
        s1.pop();
      }
      else
      {
        return false;
      }
    }
  }

  return true;
}

int main()
{
  char *ptr = nullptr;
  string s = "{{[}}]";
  bool result = isBalancedOrNot(s);
  if(result == true)
  {
    cout<<"string is balanced.\n";
  }
  else{
    cout<<"string is not balanced.\n";
  }
}
