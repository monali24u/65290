using System;

public class Test
{
  public static void Main()
  {
    string input = "Mrs Monali Patil     ";
    Console.WriteLine(input);
    int l = input.Length;

    for(int i=l; i>0; i--)
    {
      if(input[i] != ' ')
      {
        break;
      }
    }
    i++;

    int k = l;
    for(int j=i; j>0;j--)
    {
      if(input[j] != ' ')
      {
        input[k] = input[j];
        k--;
      }

      if(input[j] == ' ')
      {
        input[k] = '0';
        k--;
        input[k] = '2';
        k--;
        input[k] = '%';
        k--;
      }
    }

    Console.WriteLine(input);
  }
}
