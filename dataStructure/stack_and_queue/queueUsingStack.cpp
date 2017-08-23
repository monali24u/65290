#include<iostream>
#include <stack>
using namespace std;

class MyQueue{

public:
    stack<int> s1;
    stack<int> s2;

    MyQueue(){}

    void Enqueue(int val)
    {
      s1.push(val);
    }

    void shift()
    {
      if(s2.empty())
      {
        while(!s1.empty())
        {
          int val = s1.top();
          s2.push(val);
          s1.pop();
        }
      }
    }

    int Dequeue()
    {
      shift();
      int poppedVal = s2.top();
      s2.pop();
      return poppedVal;
    }

    int size()
    {
      return s1.size() + s2.size();
    }

};

int main()
{
  MyQueue que;
  que.Enqueue(1);
  que.Enqueue(2);
  que.Enqueue(3);
  que.Enqueue(4);
  que.Enqueue(5);

  int poppedVal = que.Dequeue();
  cout<<poppedVal<<"\n";
  


  while (!que.s2.empty())
  {
     cout << ' ' << que.s2.top();
     que.s2.pop();
  }
  cout<<"\n";

  return 0;
}
