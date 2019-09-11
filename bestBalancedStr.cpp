#include <iostream>
#include <string>
#include <stack>

using namespace std;

string bestBalancedString(string str) {
	
	stack<int> s;

	string bestStr("");
	string newStr;
	for (int i = 0; i < str.length(); ++i){
		if (str[i] == '(') s.push(i);
		else if (str[i] == ')') {
			if (s.empty()) {
				str[i] = '*';
			} else {
				s.pop();
			}
		}
	}

	while (!s.empty()){
		int i = s.top();s.pop();
		str[i] = '*';
	}

	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == '*') continue;
		bestStr.push_back(str[i]);
	}
	return bestStr;
}

int main() {

	cout<<bestBalancedString("d(e)f")<<endl;
	cout<<bestBalancedString(")(")<<endl;
	cout<<bestBalancedString("(()()(")<<endl;
}

