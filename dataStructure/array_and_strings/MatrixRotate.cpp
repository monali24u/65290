#include <iostream>
using namespace std;

void Print(int A[5][5], int size){

  for(int x = 0; x < size; x++){
     for(int y = 0; y < size; y++){
          cout<<A[x][y]<<" ";
      }
          cout<<"\n";
    }
}

void rotateMatrix(int A[5][5], int size){

  int start = 0;
  int end = size - 1;

  for(int j=0; j<(size/2); j++){

    for(int i=start; i<end; i++){

      int Temp = A[start][i];
      A[start][i] = A[end-i+start][start];
      A[end-i+start][start] = A[end][end-i+start];
      A[end][end-i+start] = A[i][end];
      A[i][end] = Temp;

    }

    start = start + 1;
    end = end - 1;
  }
  cout<<"Matrix Rotated by 90 degree."<<"\n";
  Print(A,5);
}

int main(){

int arry[5][5]=
  {
      {1,2,3,4,5},
      {6,7,8,9,10},
      {11,12,13,14,15},
      {16,17,18,19,20},
      {21,22,23,24,25}
  };
  Print(arry,5);
  rotateMatrix(arry, 5);

}
