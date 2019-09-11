#include <iostream>
#include <string>

using namespace std;

string compressString(const string & s) {
	char prev = '\0';
	int count = 1;
	string output;
	for (unsigned int j = 0; j < s.length(); ++j)
	{
		
		if (s[j] != prev) {
			if (count > 1) {
				output.push_back(count + '0');
			}
			output.push_back(s[j]);
			count = 1;
		} else {
			++count;
		}
		prev = s[j];

	}
	if (count > 1) output.push_back(count+'0');
	return output;
}

int main(){
	string s1 = "aaaaaaaaabbccccccccde";
	cout<<compressString(s1)<<endl;
	return 1;
}