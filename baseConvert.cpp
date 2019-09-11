/*
	Base Conversion
*/
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int convert_to_decimal(const string & s, int b1, int & neg) {
	int decimal = 0;

	neg = (s[0] == '-');

	for (int i = (neg ? 1:0); i < s.length(); ++i) {
		char ch = s[i];

		if (isdigit(ch)) {
			decimal = decimal*b1 + ch-'0';
		} else {
			decimal = decimal*b1 + (ch-'A'+10);
		}
	}

	cout<<"In decimal "<<decimal<<endl;
	return decimal;
} 

string convert_from_decimal(int decimal, int b2, int & neg) {

	string ans;

	while (decimal) {
		int rem  = decimal%b2;
		ans.push_back((rem > 10)? rem - 10 + 'A' :'0'+rem);
		decimal = decimal/b2;
	}
	if (neg) ans.push_back('-');
	reverse(ans.begin(),ans.end());
	return ans;
}

string convert_base(const string & s, const int b1, const int b2) {
	
	int neg;
	int decimal = convert_to_decimal(s, b1, neg);
	return convert_from_decimal(decimal,b2, neg);
}



int main() {
	cout<< convert_base("28",10,2)<<endl;
	cout<<convert_base("AA", 16, 2);
}

 