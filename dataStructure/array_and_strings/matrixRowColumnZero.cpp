#include <iostream>
using namespace std;

void Print(int A[4][4], int size){

  for(int x = 0; x < size; x++){
     for(int y = 0; y < size; y++){
          cout<<A[x][y]<<" ";
      }
          cout<<"\n";
    }
}

void MakeRowColumnZero(int M[4][4], int size){

  int s = 0;

    for(int i=1; i<size; i++){

      for(int j=1; j<size; j++){

        if(M[i][j] == 0){

          if(M[s][j] != 0){
            M[s][j] = 1;
          }
          if(M[i][s] != 0){
            M[i][s] = 1;
          }

        }
        else{

          if(M[s][j] != 0 && M[s][j] != 1){
            M[s][j] = -1;
          }
          if(M[i][s] != 0 && M[i][s] != 1){
            M[i][s] = -1;
          }
        }

      }
    }

    for(int i=1; i<size; i++){
      for(int j=1; j<size; j++){

        if((M[s][j] == 0 || M[s][j] == 1) || (M[i][s] == 0 || M[i][s] == 1))
        {
            M[i][j] = 0;
        }

      }
    }

    cout<<"after setting zero values for inner matrix"<<"\n";
    Print(M,4);

    int row  = -2;
    int column = -2;

    if(M[0][0] == 0)
    {
      row = 1;
      column = 1;
    }

    for(int i=1; i<size; i++)
    {
      if(M[0][i] == 0){
        row = 1;
      }
      if(M[i][0] == 0){
        column = 1;
      }
    }
//after setting outer row and column values
    for(int i=0; i<size; i++)
    {
      if(row == 1){
        M[0][i] = 0;
      }
      if(column == 1){
        M[i][0] = 0;
      }
    }

    cout<<"after setting whole matrix"<<"\n";
    Print(M,4);

}


int main(){

int arry[4][4]=
  {
    {2,2,2,0},
    {2,2,2,2},
    {2,2,0,2},
    {0,2,2,2}
  };
  Print(arry,4);
  MakeRowColumnZero(arry, 4);

}
