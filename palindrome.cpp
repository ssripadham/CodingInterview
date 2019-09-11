#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool isAPalindrome(const string & str) {   
    int start = 0;
    int end = str.length()-1;
    while( start <= end) {
        
        if (str[start] != str[end]) {
            return false;
        }
        
        ++start;
        --end;
    }
    
    return true;
    
}

/*
 * Complete the function below.
 */

/*
 * Complete the function below.
 */
int palindrome(string str) {

    int n = str.length();
    
    // Record the count of Palindromes
    set<string> counter;
    
    //Initialize the dp array
    vector< vector<int> > dp(n, vector<int>(n,0));
    
    //Every string of length 1 is a palindrome
    for (unsigned int i = 0; i < dp.size(); ++i) {
        dp[i][i] = 1;
        counter.insert(string(1,str[i])); 
    }
    
    //Consider each string length
    for (unsigned int len = 2; len <= n; ++len) {
        for (unsigned int start = 0; start < n - len + 1; ++start) {

            unsigned int end = start + len -1;
            
            if ((len == 2 && str[start] == str[end]) || 
                (str[start] == str[end] && dp[start+1][end-1] == 1)) {
                
                dp[start][end] = 1;
                
                string pal = str.substr(start, len);
                
                if (counter.find(pal) == counter.end()) {
                    counter.insert(pal);
                }               
                
            }
            
        }
    }
    
    return counter.size();
}

int main() {
    cout<<palindrome("aabaa")<<endl;
    //cout<<isAPalindrome("abba")<<endl;
    //cout<<isAPalindrome("abcdba")<<endl;


}