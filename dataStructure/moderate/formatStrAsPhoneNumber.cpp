#include<iostream>
#include<string>
using namespace std;

string formatString(string s)
{
  int size = s.length();
  string outputStr = "";
  int count = 0;

  for(int i=0; i<size; i++)
  {
    if(s[i] == '-' || s[i] == ' ')
    {
      continue;
    }
    else
    {
      outputStr = outputStr + s[i];
      count = count + 1;

      if(count == 3)
      {
        outputStr = outputStr + '-';
        count = 0;
      }
    }
  }

  if(outputStr[outputStr.length()-1] == '-')
  {
    return(outputStr.substr(0, outputStr.length()-1));
  }

  if(count == 1)
  {
    int size = outputStr.length();
    char c = outputStr[size-2];
    outputStr[size-2] = outputStr[size-3];
    outputStr[size-3] = c;
  }

  return outputStr;
}


int main()
{
  //string s = "00-44  48-5555 8361";
  string s = "0 - 22 1985--324";
  //string s = "555372654";
  string output = formatString(s);
  cout<<output<<endl;

  return 0;
}
