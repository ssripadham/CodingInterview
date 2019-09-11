#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int numRange(vector<int> &A, int B, int C) {
    // Do not write main() function.
    // Do
     not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
        
    int mini = min(B,C);
    int maxi = max(B,C);
    int sum=0;
    
    queue<int> q;
    int count = 0;
    for (int i=0; i < A.size(); ++i) {
    
        cout<<"--------"<<endl<<A[i]<<endl<<"----------"<<endl;
        q.push(A[i]);
  
        if (A[i]>maxi) {
            while (!q.empty()){
                q.pop();
                sum = 0;
            }
            continue;
        }    
  
        sum = sum + A[i];
        if (sum < mini) continue;
 
        //cout<<sum<<endl; 
         while (sum > maxi) {
            int val = q.front();q.pop();
            cout<<val<<" "<<sum<<endl;
            sum -= val;
        }
        cout<<"Sum+"<<sum<<endl;

        
        ++count;
    }
    return count;
}

int main(){
    vector<int> v = {80, 97, 78, 45, 23, 38, 38, 93, 83, 16, 91, 69, 18, 82, 60, 50, 61, 70, 15, 6, 52, 90};
    cout<<numRange(v,99,269);
}