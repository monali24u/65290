#include <iostream>
#include <string>
using namespace std;

string CompressedStr(string input)
{
	string output = "";
  for(int i=0; i<input.length(); i++){
    output = output+input[i];
    int j= i+1;
    int count = 1;

    while(input[i] == input[j]){
      i++;
      j++;
      count++;
    }
    char cnt = count + '0';
    output = output+cnt;
  }
  return output;
}

int main(){

  string input = "aabbccca";
  string result = CompressedStr(input);
  cout<<result;

  if(result.length() < input.length()){
    cout<<"Compressed string is:- "<<result;
  }
  else
  {
    cout<<"Compressed string is not smaller. Hence output is:- "<<input;
  }
  return 0;
}
