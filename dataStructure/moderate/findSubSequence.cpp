#include<iostream>
using namespace std;

int findLeftSorted(int A[], int size)
{
  for(int i=1; i<size-1; i++)
  {
    if(A[i-1] > A[i])
    {
      return i-1;
    }
  }
  return size-1;
}

int findRightSorted(int A[], int size)
{
  for(int i=size-2; i>=0; i--)
  {
    if(A[i] > A[i+1])
    {
      return i+1;
    }
  }
  return 0;
}

int findMinLeft(int A[], int size, int min, int start)
{
  for(int i=start; i>=0; i--)
  {
    if(A[i] < A[min])
    {
      return i+1;
    }
  }

  return 0;
}

int findMaxRight(int A[], int size, int max, int end)
{
  for(int i=end; i<size; i++)
  {
    if(A[i] > A[max])
    {
      return i-1;
    }
  }

  return size-1;
}

void findSubSequence(int A[], int size)
{
  int leftStart = 0;
  int leftEnd = findLeftSorted(A, size);
  int rightStart = findRightSorted(A, size);
  int rightEnd = size-1;
  int minIndex = leftEnd + 1;
  int maxIndex = rightStart - 1;

  if(minIndex > size-1 || maxIndex < 0)
  {
    cout<<"array already sorted."<<endl;
    return;
  }

  int M = findMinLeft(A, size, minIndex, leftEnd);
  int N = findMaxRight(A, size, maxIndex, rightStart);

  cout<<"("<<M<<" "<<N<<")"<<endl;

}

int main()
{
  int A[] = {1,2,4,6,1,2,4,6};
  int size = 8;
  findSubSequence(A, size);
  return 0;
}
