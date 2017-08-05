using System;
using System.Linq;

public class Test
{
	public static void Main()
	{
		// your code goes here
		string input = "important";

		if(String.IsNullOrEmpty(input))
		{
			Console.WriteLine("string is NULL");
			return;
		}

		if(input.Length == 1)
		{
			Console.WriteLine("string has all unique chars");
			return;
		}

		int[] MyArray = Enumerable.Repeat(0,256).ToArray();

		for(int i=0; i<input.Length; i++)
		{
			int num = Convert.ToInt32(input[i]);

			if(MyArray[num] == 0)
			{
				MyArray[num] = MyArray[num] + 1;
			}
			else
			{
				Console.WriteLine("string does not has all unique chars. Repeated character is ");
				Console.WriteLine(input[i]);
				return;
			}
		}

		Console.WriteLine("string has all unique chars");
	}
}
