/*
Given two strings where first string may contain wild card characters and second string is a
normal string. Write a function that returns true if the two strings match.
The following are allowed wild card characters in first string.

* --> Matches with 0 or more instances of any character or set of characters.
? --> Matches with any one character.

*/
#include <iostream>

using namespace std;

bool wildCard(const string & regexp, const string & matchStr, int reIndex, int strIndex){

	if (strIndex == matchStr.length()) {
		return reIndex == regexp.length();
	}

	if (reIndex == regexp.length()) {
		return strIndex == matchStr.length();
	}

	if (regexp[reIndex] == matchStr[strIndex]) {
		return wildCard(regexp, matchStr, reIndex+1, strIndex+1);
	} else if (regexp[reIndex] == '*') {
		return wildCard(regexp, matchStr, reIndex, strIndex+1) || 
				wildCard(regexp, matchStr, reIndex+1, strIndex+1);
	} else if (regexp[reIndex] == '?') {
		return wildCard(regexp, matchStr, reIndex+1,strIndex+1);
	}	
	return false;
}

int main() {

	cout<<wildCard("t*e","treehouse",0,0)<<endl;
	cout<<wildCard("t?e","treehouse",0,0)<<endl;
	cout<<wildCard("t*s","treehouse",0,0)<<endl;
	cout<<wildCard("t*ez","treehouse",0,0)<<endl;
	cout<<wildCard("treehouse","treehouse",0,0)<<endl;
	cout<<wildCard("tr?eh*","treehouse",0,0)<<endl;
	cout<<wildCard("*", "treehouse",0,0)<<endl;
	cout<<wildCard("?","treehouse",0,0)<<endl;

}





