#include<iostream>
using namespace std;

int searchMax(int A[], int length)
{
  int start = 0;
  int end = length-1;
  int mid;

  while(start < end)
  {
    mid = (start + end)/2;

    //only two elements in array
    if((end-start) == 1)
    {
      if(A[start] > A[end])
      {
        return A[start];
      }
      else
      {
        return A[end];
      }
    }

    if((A[mid-1] < A[mid]) &&  (A[mid] > A[mid+1]))
    {
      return A[mid];
    }
    else if((A[mid-1] < A[mid]) && (A[mid] < A[mid+1]))
    {
      start = mid+1;
    }
    else if((A[mid-1] > A[mid]) &&(A[mid] > A[mid+1]))
    {
      end = mid-1;
    }

  }

  if(start == end)
  {
    return A[start];
  }

  return -1;
}

int main()
{
  int A[] = {1,2,3,8,9,10,8,5,-3,-1};
  int result = searchMax(A, 10);
  cout<<"Max is:- "<<result<<" "<<endl;
  return 0;
}
