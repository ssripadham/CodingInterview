#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<int> > threeSum(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    unordered_map<int, vector<vector<int>>> _map;
    for (int i = 0; i< A.size(); ++i) {
        for (int j = 0; j < A.size(); ++j){
            if (i >= j) continue;
            int two_sum = A[i]+A[j];
            cout << i<<" "<<j<<" "<<A[i] << " "<<A[j]<<endl;

            auto iter = _map.find(two_sum);
            
            if (iter == _map.end()) {
                vector<vector<int>> grid;
                cout<<"Pushing "<<A[j]<<","<<A[i]<<endl;
                vector<int> v = { A[j], A[i] };
                grid.push_back(v);
                _map[two_sum] = grid;
            } else {
                //vector<vector<int>> grid = iter->second;
                vector<int> v = { A[j], A[i] };
                cout<<"-Pushing "<<A[j]<<","<<A[i]<<endl;
                //grid.push_back(v);
                //_map[two_sum] = grid;
                _map[two_sum].push_back(v);
            }
        }
    }



    vector<vector<int>> grid,output;
    for (int i =0; i<A.size(); ++i){
        auto iter = _map.find(-A[i]);
        if (iter != _map.end()) {
             grid = iter->second;
             for (int j = 0; j < grid.size(); ++j) {
                 grid[j].push_back(A[i]);
                 output.push_back(grid[j]);
             }
        }
    }

    return output;
}

int main() {
    vector<int> v = {1, -4, 0, 0, 5, -5, 1, 0, -2, 4, -4, 1, -1, -4, 3, 4, -1, -1, -3};
    threeSum(v);
}