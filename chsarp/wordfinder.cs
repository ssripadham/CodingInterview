using System;
using System.Collections.Generic;

//
//  0123
//  xyyzyzyx
//         i
//       j
//
// x 1
// y 2 
// z 1
// count 3  == arr.Lenght

// zyx
// xyyz
// O(N)
// O(k)


class Solution
{
    public static string GetShortestUniqueSubstring(char[] arr, string str)
    {
      var freq = new Dictionary<int, int>();
      int maxCount = int.MaxValue;
      string result = "";
      int len = str.Length;
      
      foreach(var a in arr) freq.Add(a, 0);

      int i = 0;
      int j = 0;
      int count = 0;

      while(i < len)
      {
        if (freq.ContainsKey(str[i]))
        {
          if (freq[str[i]] == 0)
          {
            count++;
          }
          freq[str[i]]++;
        }
        
        while (count == arr.Length)
        {
          
//  xyyzyzyx
//         i
//   j          
//          Console.WriteLine("got here " + (i - j + 1)  + " : " + str[j]);
          if ((i - j + 1) < maxCount)
          {
            maxCount = i - j + 1;
            result = str.Substring(j, maxCount);
          }
          
          if (freq.ContainsKey(str[j]))
          {
            if (freq[str[j]] == 1)
            {
  //          Console.WriteLine("count : " + count + " : " + str[j]);            
               count--;
            }
            freq[str[j]]--;            
          }

          j++;
        }
        
        i++;
      }
      
      
      return result;
      
      
    }

    static void Main(string[] args)
    {
      // ["A","B","C"], "ADOBECODEBANCDDD"
      var arr = new char[]{'A','B','C'};
      var str = "ADOBECODEBANCDDD";
      var result = GetShortestUniqueSubstring(arr, str);
      Console.WriteLine(result);
    }
}

