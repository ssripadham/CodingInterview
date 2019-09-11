#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> wrongPlusOne(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size();
    
    int offset = 0;
    if (A.size() != 1) {
        while(A[offset++] == 0) {}
    }
    
    
    long long sum = 0;
    for (int i = offset; i < n; ++i) {
        sum = sum*10 + A[i]; 
        cout<<A[i]<<" "<<sum<<endl;
    }

    sum += 1;
    
    cout<<sum<<endl;
    vector<int> output;

    while (sum) {
        output.push_back(sum % 10);
        sum = sum/10;
    }    
    
    std::reverse(output.begin(), output.end());
    return output;
}


vector<int> plusOne(vector<int> & A) {    
    int n = A.size();
    
    int offset = 0;
    if (A.size() != 1) {
        while(A[offset] == 0) { offset++; }
    }
    
    vector<int> output;
    int carry = 1;
    for (int j = n-1; j >= offset; --j){
        int sum = A[j]+carry;
        output.push_back(sum%10);
        carry = sum/10;
    }
    
    if (carry) output.push_back(carry);
    
    std::reverse(output.begin(), output.end());
    return output;
}

int main () {
    vector<int> v = { 0, 3, 7, 6, 4, 0, 5, 5, 5 };
    vector<int> output = plusOne(v);
    copy(output.begin(), output.end(), ostream_iterator<int>(cout," "));

}