#include<iostream>
using namespace std;

bool findElementInMatrix(int A[5][5], int val, int size)
{
  int row = 0;
  int column = size-1;

  while(row <= size-1 && column >= 0)
  {
    if(A[row][column] == val)
    {
      cout<<"element found in Matrix A["<<row<<"]["<<column<<"]"<<endl;
      return true;
    }
    else if(A[row][column] < val)
    {
      row = row + 1;
    }
    else if(A[row][column] > val)
    {
      column = column - 1;
    }
  }

  return false;
}

int main()
{
  int arry[5][5]=
  {
      {1,2,3,4,5},
      {6,7,8,9,10},
      {11,12,13,14,15},
      {16,17,18,19,20},
      {21,22,23,24,25}
  };

  bool flag = findElementInMatrix(arry, 26, 5);

  if(flag == false)
  {
    cout<<"element not found in Matrix"<<endl;
  }

}
