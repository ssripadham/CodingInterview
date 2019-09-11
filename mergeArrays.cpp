#include <vector>
#include <iostream>

using namespace std;

/*
 * Complete the function below.
 */
vector < int > mergeArrays(vector < int > a, vector < int > b) {
    
    vector<int> output;
    
    //Pointers to indices of a & b respectively
    int i=0, j = 0;
    
    while (i < a.size() && j < b.size()) {
        cout<<i<<" "<<j<<endl;
        if (a[i] < b[j]) {
            output.push_back(a[i]); i++;
        } else {
            output.push_back(b[j]); j++;
        }
        
    }
    
    // Now push the remaining elements in a & b
    while (i < a.size()) {
        output.push_back(a[i++]);
    }
    
    while (j < b.size()) {
        output.push_back(b[j++]);
    }
    
    return output;

}

int main() {
    vector<int> v1 = {2,4,6};
    vector<int> v2 = {1,3,5};
    vector<int> v3 =mergeArrays(v1,v2);
}