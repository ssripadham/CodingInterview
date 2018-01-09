/*
Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Input:
First line of the input contains no of test cases  T,the T test cases follow.
Each test case consist of 2 space separated integers A and B denoting the size of string str1 and str2 respectively
The next two lines contains the 2 string str1 and str2 .


Output:
For each test case print the length of longest  common subsequence of the two strings .


Constraints:
1<=T<=200
1<=size(str1),size(str2)<=100


Example:
Input:
2
6 6
ABCDGH
AEDFHR
3 2
ABC
AC

Output:
3
2

Explanation
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.

LCS of "ABC" and "AC" is "AC" of length 2
 */
 // A Sample C++ program for beginners with Competitive Programming
#include <iostream>
#include <algorithm>

using namespace std;

int lcs(string str1, string str2){
    vector<vector<int>> a(str1.length()+1, vector<int>(str2.length()+1,0));
    for (int i = 1; i <= str1.length(); ++i){
        for (int j = 1; j <= str2.length(); ++j) {
            if (str1[i-1] == str2[j-1]) {
                a[i][j] = a[i-1][j-1] + 1;
            } else {
                a[i][j] = max(a[i-1][j], a[i][j-1]);
            }
        }
    }
    return a[str1.length()][str2.length()];
}

int main() {
	//code
	int n, len2, len1;
    cin >> n ;
    string str1, str2;
    for (int i=0; i<n; i++)
    {
        cin >> len1 >> len2;
        cin >> str1 >> str2;
        cout << lcs(str1, str2) <<endl;
    }
	return 0;
}

