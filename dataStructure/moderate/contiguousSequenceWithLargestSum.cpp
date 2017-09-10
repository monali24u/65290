#include<iostream>
using namespace std;

void findContiguousSequenceWithLargestSum(int A[], int size)
{
  int sum = A[0];
  int maxSum = A[0];
  int startIndex = 0;
  int endIndex = 0;
  int startMaxIndex = startIndex;
  int endMaxIndex = 0;

  for(int i=1; i<size; i++)
  {
    sum = sum + A[i];
    endIndex = i;

    if(sum > maxSum)
    {
      maxSum = sum;
      startMaxIndex = startIndex;
      endMaxIndex = endIndex;
    }
    else if(sum < 0)
    {
      sum = 0;
      startIndex = i+1;
      endIndex = i+1;
    }
  }

  cout<<"maxSum:- "<<maxSum<<" ContiguousSequenceWithLargestSum:- "<<startMaxIndex<<" "<<endMaxIndex<<endl;

}

int main()
{
  int A[] = {2,3,-2,4,-10,-8,4,-1,5};
  findContiguousSequenceWithLargestSum(A, 9);
  return 0;
}
