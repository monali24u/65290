#include<iostream>
using namespace std;

int findLeftSorted(int A[], int size)
{
  for(int i=1; i<size; i++)
  {
    if(A[i-1] > A[i])
    {
      return i-1;
    }
  }
  return size-1;
}

void swapTwoElementsToGetSortedArray(int A[], int size)
{
  int firstToSwap = findLeftSorted(A,size);
  int secondToSwap;

  if(firstToSwap+1 == size-1)
  {
    cout<<"wrong Input"<<endl;
    return;
  }

  for(int i=firstToSwap+1; i<size; i++)
  {
    if(A[i] > A[firstToSwap])
    {
      secondToSwap = i-1;
      break;
    }
  }

  int temp = A[firstToSwap];
  A[firstToSwap] = A[secondToSwap];
  A[secondToSwap] = temp;

}

int main()
{
  int A[] = {3,3,7,9,5};
  int size = 5;

  for(int i=0; i<size; i++)
  {
    cout<<A[i]<<" ";
  }
  cout<<endl;
  swapTwoElementsToGetSortedArray(A, size);

  for(int i=0; i<size; i++)
  {
    cout<<A[i]<<" ";
  }
  cout<<endl;

  return 0;
}
