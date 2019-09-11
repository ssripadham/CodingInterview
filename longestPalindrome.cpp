#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
Given a string, find the longest substring which is palindrome. For example, if the given string is
 “forgeeksskeegfor”, the output should be “geeksskeeg”.
*/

string findLongestPalindrome(const string & str){

	int myStart = 0;
	int maxLength = 1;

	vector< vector<int>> dp(str.length(), vector<int>(str.length())) ;

	for (int i = 0; i < str.length(); ++i) {
		dp[i][i] = 1;
	}

	for (int start = 0; start < str.length() -1; ++start){
		if (str[start] == str[start+1]) {
			dp[start][start+1] = 2;
			myStart = start;
		}
	}

	maxLength = 2;	
	for (int len = 3; len <= str.length(); len++){
		for (int start = 0; start < str.length()-len+1; ++start) {
			int end = len + start - 1;
			if (dp[start+1][end-1] >= 1 and str[start] == str[end] ){
				dp[start][end] = dp[start+1][end-1] + 2;

				if (len > maxLength){
					maxLength = len;
					myStart = start;
				}
			}

		}
	}

	cout << "Longest Palindrome: ";
	for (int l=0; l < maxLength; l++) {
		cout<<str[myStart+l];
	}
	cout<<endl;
}

int main() {

	cout<<findLongestPalindrome("forgeeksskeegfor")<<endl;

}
