#include<iostream>
using namespace std;

int binarySearch(int A[], int x)
{
  int low = 0;
  int high = 7;
  int mid;


  while(low <= high)
  {
    mid = (low+high)/2;

    if(A[mid] < x)
    {
      low = mid+1;
    }
    else if(A[mid] > x)
    {
      high = mid-1;
    }
    else
    {
      return mid;
    }
  }

  return -1;
}

int binarySearchRecursive(int A[], int x, int low, int high)
{
  if(low <= high) return -1;

  int mid = (low+high)/2;

  if(A[mid] < x)
  {
    binarySearchRecursive(A, x, mid+1, high);
  }
  else if(A[mid] > x)
  {
    binarySearchRecursive(A, x, low, mid-1);
  }
  else
  {
    return mid;
  }
}

int main()
{
  int A[] = {1,2,3,5,6,7,9,10};
  int result = binarySearch(A, 10);
  cout<<A[result]<<"\n";

  int result1 = binarySearchRecursive(A, 10, 0, 7);
  cout<<A[result1s]<<"\n";
  return 0;
}
