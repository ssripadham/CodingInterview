#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;



void telephone(const string & number, int index, string strSoFar, unordered_map<char, string> & myMap) {
	
	if (index == number.length()-1){
		cout<<strSoFar<<endl;
		return;
	}

	string digits = myMap[number[index]];
	for (int i = 0; i < digits.length(); ++i){
		strSoFar.push_back(digits[i]);
		telephone(number, index+1, strSoFar, myMap);
		strSoFar.pop_back();
	}
	return;

}

int main(){
 unordered_map<char, string> myMap;

 myMap['0'] = "0";
 myMap['1'] = "1";
 myMap['2'] = "ABC";
 myMap['3'] = "DEF";
 myMap['4'] = "GHI";
 myMap['5'] = "JKL";
 myMap['6'] = "MNO";
 myMap['7'] = "PQRS";
 myMap['8'] = "TUV";
 myMap['9'] = "WXYZ";

  telephone("4087302499", 0, "", myMap);
}