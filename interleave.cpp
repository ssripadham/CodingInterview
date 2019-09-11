#include <string>
#include <iostream>

using namespace std;

void interleave(string s1, string s2,
                unsigned int index1, unsigned int index2,
                string output) {
    if (output.length()== s1.length()+s2.length()) {
        cout<<output<<endl;
        return;
    }
    if (index1 < s1.length()) {
        interleave(s1, s2, index1+1, index2, output+s1[index1]);
    }
    
    if (index2 < s2.length()) {
        interleave(s1,s2, index1, index2+1, output+s2[index2]);
    }
    
}

int main() {
    interleave("ab","cd",0,0,"");
}