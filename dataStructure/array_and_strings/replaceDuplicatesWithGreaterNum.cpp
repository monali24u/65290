//Replace the duplicates with a number greater than the duplicate number to give the least sum
//i.e. if the given array has these numbers 4 3 2 2 6, in this "2" is the duplicate number and 
//this can be updated to the next greater non-duplicate number "5",
//so the numbers will be 4 3 2 5 6 and the minimum sum is 20 (4+3+2+5+6)

#include<iostream>
#include<unordered_set>
using namespace std;

int replaceDuplicatesWithGreaterNum(int A[], int size)
{
  unordered_set<int> htable;
  unordered_set<int>::const_iterator got;
  htable.insert(A[0]);
  int sum = A[0];

  for(int i=1; i<size; i++)
  {
    got = htable.find(A[i]);

    if(got != htable.end())
    {
      bool notFound = true;
      int temp = *got;

      while(notFound)
      {
        temp = temp + 1;
        got = htable.find(temp);

        if(got != htable.end())
        {
          continue;
        }
        else
        {
          sum = sum + temp;
          htable.insert(temp);
          A[i] = temp;
          notFound = false;
        }
      }
    }
    else
    {
      sum = sum + A[i];
      htable.insert(A[i]);
    }
  }

  return sum;
}

void printArray(int A[], int size)
{
  for(int i=0; i<size; i++)
  {
    cout<<A[i]<<" ";
  }
  cout<<endl;
}

int main()
{
  int array[] = {4,3,2,2,6,9,7,5};
  int size = sizeof(array)/sizeof(array[0]);
  cout<<"input array:- ";
  printArray(array,size);
  int sum = replaceDuplicatesWithGreaterNum(array,size);
  cout<<"sum:- "<<sum<<endl;
  cout<<"output array:- ";
  printArray(array,size);

  return 0;
}
