/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.

[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

#include <vector>
using namespace std;

int searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int low = 0;
    int high = A.size()-1;
    
    while (high >= low) {
        
        int mid = low + (high -low)/2;
        
        if (A[mid] == B) return mid;
        
        if (A[mid] > B) 
            high = mid - 1;
        else
            low = mid + 1;
    }
    
    return (B< A[high])? high : high + 1;
    
}
