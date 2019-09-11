#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addBinary(string & s1, string & s2) {
	
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(),s2.end());

	string output;
	int carry = 0;
	for (int i =0, j=0; i < s1.length() && j < s2.length(); ++i, ++j) {
		int x = (i < s1.length()) ? s1[i] - '0' : 0;
		int y = (j < s2.length()) ? s2[j] - '0' : 0;

		output.push_back(x^y+'0');
		carry = x & y;

	}
	if (carry !=0 ) output.push_back(carry+'0');
	reverse(output.begin(), output.end());
	return output;

}

int main() {
	
	string s1("100");
	string s2("101");
	cout<<addBinary(s1, s2)<<endl;

}
