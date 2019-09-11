#include <algorithm>
#include <assert.h>
#include <iterator>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {

        int r = 0;
        int c = 0;
        int i = 0;
        vector<vector <char> > v(numRows); //no need for allocating second dim

        while (i < s.length()){
            while (r < numRows && i < s.length())
            {
                v[r].push_back(s[i]); 
                cout<<r<<","<<s[i]<<" : ";
                i++;r++;
            }
        
            --r; --r;
            while (r >= 0 && i < s.length())
            {
                v[r].push_back(s[i]);
                cout<<r<<","<<s[i]<<" : ";
                i++; --r;
            }
            cout<<endl<<r<<endl;
            ++r;++r;
        }


        string outStr;
        for (int row = 0; row < v.size(); ++row){
            auto iter = v[row].begin();
            while (iter != v[row].end()) {
                outStr += *iter;
                iter++;
            }
        }
        return outStr;
    }


        
};

int main() {
    Solution s;
    auto outStr = s.convert("PAYPALISHIRING",4);
    //assert(outStr == "PAHNAPLSIIGYIR");
    cout<<outStr<<endl;
    return 0;
}