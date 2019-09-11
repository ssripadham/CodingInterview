#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> getVersionVector(string & version) {
    int startPos = 0;    
    vector<int> output;
    while (startPos != string::npos) {
        int pos = version.find_first_of('.', startPos);

        string version_num = version.substr(startPos,pos);
        if (version_num.empty()) version_num="0";
        
        int vI = atoi(version_num.c_str());
        output.push_back(vI);

        if (pos == string::npos) break;    
        startPos = pos + 1;
        
    }

    return output;
}

int compareVersion(string A, string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    
    vector<int> v1 = getVersionVector(A);
    vector<int> v2 = getVersionVector(B);
    //copy(v1.begin(), v1.end(), ostream_iterator<int>(cout," "));cout<<endl;
    //copy(v2.begin(), v2.end(), ostream_iterator<int>(cout," "));cout<<endl;
    int i,j;
    for (i = 0, j = 0; i < v1.size()  && j< v2.size(); ++i, ++j) {

        if (v1[i] > v2[j]) { return 1; }
        if (v1[i] < v2[j]) { return -1; }
    }

    if (i < v1.size()) return 1;
    if (j < v2.size()) return -1;
    return 0;
    
}

int main() {

    vector<string> v = {"0.1","1.2","1.1","1.13"};
    sort(v.begin(), v.end(), compareVersion);
    copy(v.begin(), v.end(), ostream_iterator<string>(cout," "));
}