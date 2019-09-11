#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

string convertInt(int i) {
    if (i==0) return "0";
    string str;
    while (i) {
        str += i%10 + '0';
        i = i/10;
    }
    reverse(str.begin(), str.end());
    return str;
}

bool compare(string s1, string s2) {

	return strcmp((s2+s1).c_str(), (s1+s2).c_str()) < 0;
/*
	//cout<<s1<<" "<<s2<<endl;
	int i, j;	
	for (i =0, j=0; i < s1.length() || j < s2.length(); i++, j++) {
		if (s1[i] < s2[j]) return false;
		if (s1[i] > s2[j]) return true;
	}

	while (i < s1.length()){
		if (s1[i] < s2[j-1]) return true;
		i++;
	}

	while (j < s2.length()){
		if (s1[i-1] < s2[j]) return false;
		j++;
	}

	return true;
	*/
}


string largestNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<string> b;
    for (int i = 0; i < A.size(); ++i) {
        b.push_back(convertInt(A[i]));
    }
   
    
    sort(b.begin(), b.end(), compare);
    
    
    string str;
    for (int i = 0; i< b.size(); ++i){
        str += b[i];
    }
    
    return str;
}

int main() {
	
	//vector<int> v = { 3, 30, 34, 5, 9 };
	//vector<int> v = { 980, 674, 250, 359, 98, 969, 143, 379, 363, 106, 838, 923, 969, 880, 997, 664, 152, 329, 975, 377, 995, 943, 369, 515, 722, 302, 496, 124, 692, 993, 341, 785, 400, 113, 302, 563, 121, 230, 358, 911, 437, 438, 494, 599, 168, 866, 689, 444, 684, 365, 470, 176, 910, 204, 324, 657, 161, 884, 623, 814, 231, 694, 399, 126, 426};
	vector<int> v = {0};
	cout<<largestNumber(v);

} 