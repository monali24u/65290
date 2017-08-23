#include<iostream>
#include <stack>
using namespace std;

stack<int> s1;
stack<int> s2;

void sortStack(){

  while(!s1.empty())
  {
    int tmp = s1.top();
    s1.pop();

    while(!s2.empty() && s2.top() > tmp)
    {
      s1.push(s2.top());
      s2.pop();
    }

    s2.push(tmp);
  }
}

int main()
{

  s1.push(5);
  s1.push(3);
  s1.push(1);
  s1.push(4);
  s1.push(6);
  s1.push(2);

  sortStack();

  cout<<"sorted stack is:- \n";
  while (!s2.empty())
  {
     cout << ' ' <<s2.top();
     s2.pop();
  }
  cout<<"\n";

  return 0;
}
