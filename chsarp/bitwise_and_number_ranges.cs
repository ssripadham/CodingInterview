/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4
Example 2:

Input: [0,1]
Output: 0
*/

public class Solution {
    public int RangeBitwiseAnd(int m, int n) {
        var binary1 = Convert.ToString(m, 2);
        var binary2 = Convert.ToString(n, 2);
        
        if (binary1.Length != binary2.Length) return 0;
        
        var result = 0;
        for (var i = 0; i < binary1.Length; i++)
        {
            if (binary1[i] == binary2[i])
            {
                if (binary1[i] == '1') {
                    result += (int)Math.Pow(2, binary1.Length - 1 - i);
                }
            }
            else
            {
                break;
            }
        }
        return result;
        /*
        var binary = new BitArray(new int[]{0});
        binary.SetAll(true);
        var len1 = Convert.ToString(m, 2).Length;
        var len2 = Convert.ToString(n, 2).Length;
        if (len1 != len2) return 0;
        
        Console.WriteLine(n);
        for (int i=m; i <= n; ++i){
            var x = new BitArray(new[] { i });                       
            binary = binary.And(x);
            
            var result1 = new int[1];
            binary.CopyTo(result1, 0);
            Console.WriteLine($"{result1[0]}");
        }
        

        var result = new int[1];
        binary.CopyTo(result, 0);
        return result[0];
        */
        
    }
}
/*
101
110    
111
 1 0 0 
 */
