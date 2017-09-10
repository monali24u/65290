#include<iostream>
using namespace std;

int partition(int A[], int left, int right)
{
  int pivot = A[(left+right)/2];

  while(left <= right)
  {
    while(A[left] < pivot)
    {
      left++;
    }

    while(A[right] > pivot)
    {
      right--;
    }

    if(left <= right)
    {
      int temp = A[left];
      A[left] = A[right];
      A[right] = temp;
      left++;
      right--;
    }
  }
  return left;
}

void quickSort(int A[], int left, int right)
{
  int index = partition(A, left, right);

  if(left < index-1)
  {
    quickSort(A, left, index-1);
  }
  if(index < right)
  {
    quickSort(A, index, right);
  }
}

int main()
{
  int A[] = {5,1,7,3,2,6};
  for(int i=0; i<6; i++)
  {
    cout<<A[i]<<" ";
  }
  quickSort(A, 0, 5);
  cout<<"\nafter sorting: "<<"\n";
  for(int i=0; i<6; i++)
  {
    cout<<A[i]<<" ";
  }

  return 0;
}
