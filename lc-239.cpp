/*
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 
Explanation: 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Note: 
You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.
*/
 
class Solution {
public:
    
    struct MyComparison{
        
        bool operator() (pair<int, int> a, pair<int, int> b){
            return a.first < b.first;
        }
        
    };
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       
        vector<int> output;
        if (k > nums.size()){
            return output;
        }
        
        //Build max priority queue
        
        priority_queue< pair<int, int>, vector<pair<int, int>>, MyComparison> pq;
        
        for (int i=0; i< nums.size(); ++i){
            
            if (i < k){
                pq.push(make_pair(nums[i], i));
            } else {
                pq.push(make_pair(nums[i],i));
                while (pq.top().second <= i-k) pq.pop();
            }
            
            if (i >= k-1) output.push_back(pq.top().first);
        }
            
        return output;
    }
};