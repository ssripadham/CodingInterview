public class Solution {
    public int ArrangeCoins(int n) {
        if (n < 0) return 0;
        int i = 1;
        while (true){
            
            if (n-i < 0)
                break;
            n = n - i;
            ++i;
        }
        
        return i-1;
    }
}