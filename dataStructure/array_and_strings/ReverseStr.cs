using System;

public class Test
{
  public static void Main(){

    string input = "welcome";

    char[] array = new char[input.Length];
    int forward = 0;
    for(int i = input.Length - 1; i >= 0; i--)
    {
        array[forward] = input[i];
        forward++;
    }
    Console.WriteLine(array);
  }

}
