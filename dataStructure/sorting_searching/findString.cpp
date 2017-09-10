#include<iostream>
#include<string>
using namespace std;

int findString(string A[], int start, int end, string val)
{
  if(start > end) return -1;

  if(val == "") return -1;

  int mid = (start + end)/2;

  if(A[mid] == val)
  {
    return mid;
  }

  if(A[mid] != "")
  {
    if(A[mid].compare(val) < 0) //A[mid] is less than val
    {
      //search right
      return findString(A, mid+1, end, val);
    }
    else
    {
      return findString(A, start, mid-1, val);
    }
  }

  if(A[mid] == "")
  {
    int left = mid - 1;
    int right = mid + 1;

    while((start <= left) && (A[left] == ""))
    {
      left = left - 1;
    }

    while((right <= end) && (A[right] == ""))
    {
      right = right + 1;
    }

    if(A[left] != "" && A[left].compare(val) < 0)
    {
      //search right
      return findString(A, mid+1, end, val);
    }
    else if(A[right] != "" && A[right].compare(val) > 0)
    {
      return findString(A, start, mid-1, val);
    }

  }

  return -1;
}


int main()
{
  string arry[] = {"at","","","","ball","","","cat","","","dog","",""};
  string val = "cat";

  int result = findString(arry, 0, 12, val);

  if(result == -1)
  {
    cout<<"given string not available in given array."<<endl;
  }
  else
  {
    cout<<"string found at index "<<result<<endl;
  }

  return 0;
}
