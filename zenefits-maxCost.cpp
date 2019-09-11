#include <iostream>
#include <queue>

/*
int maxCost( vector<int> v, int n, int index, int numRemaining) {

	if (numRemaining == 0)
		return 0;
	}


	int cost = maxCost(v, n, index+1, numRemaining);
	for(int i = 0; i < n ; ++i) {

		if (v[i] > 0) {
			v[i] = v[i] - 1;
			cost[] = v[i] + (v, n, numRemaining - 1);
			v[i] = v[i] + 1;
		}

	}

	vector<int> dp(M-1);
	int bestCost = INT_MIN;
	dp[0] = v[0];//first ticket always pick from first window
	int remaining = M;
	for (int i = 1; i < M; ++i ) {
		for (int j = 0;j < n;++j) {
			//cost from using prev window
			dp[i] = dp[i-1] + sumTo(remaining, v[i]), 
			remaining =  M - v[i];

			//Cost without using ith window
			sumTo(M, v[i])
			remaining = M-v[i]
		}
	}


}

int sumTo(int numTerms, v[i]) {
	if (v[i] < numTerms) {
		return numTerms*(numTerms+1)/2;
	}

}
*/
#include <iterator>
#include <algorithm>
#include <vector>


using namespace std;
/*
int maxCostA(vector<int> & v, int m){

	std::vector<int>::iterator result;
	int cost=0;
	int i;

	while(m) {

	    result = std::max_element(v.begin(), v.end());
    	i = std::distance(v.begin(), result);
    	//cout<<"index="<<i<<endl;
    	cost = cost + v[i];
    	//cout<<"cost="<<cost;cout<<" "<<m;
    	v[i] = v[i]-1;
		m = m - 1;
	}

	return cost;

int maxCost(vector<int> & v, int m) {
    
    priority_queue<int> max_heap(v.begin(), v.end());



 
    int cost = 0;
    int max_avail;
  
    int i;
    while(m){
        max_avail = max_heap.top();
        max_heap.pop();
        
        
        if (m>2) {
            cost += 2*max_avail - 1;
            max_avail -= 2;
            m = m-2;
        } else {
            //One ticket left
            cost += max_avail;
            --max_avail;
            m = m -1;
        }   
        max_heap.push(max_avail);
    }
    return cost;
}

int maxCost1(vector<int> & v, int m) {
    
    priority_queue<int> max_heap(v.begin(), v.end());
    int cost = 0;
    int max_avail;
    int i;
    while(m){
        max_avail = max_heap.top();
        max_heap.pop();
        cost += max_avail;
        --max_avail;
        max_heap.push(max_avail);
        --m;
    }
    return cost;
}
*/


int maxCost(vector<int> & v, int m) {
    
    priority_queue<int> max_heap(v.begin(), v.end());
    int cost = 0;
    int max_avail;
    int next_highest;
   
    while (true) {
       
        max_avail = max_heap.top();
        max_heap.pop();
        
        next_highest = max_heap.top();
        
        int num_drawn = max_avail - next_highest+1;
        
        if (m < num_drawn) {
            break;
        }

		cout<<num_drawn<<" "<<max_avail<<endl;        
        cost += num_drawn*max_avail - ((num_drawn*(num_drawn-1))/2);
        cout<<cost<<endl;
        max_avail -= num_drawn;
        m = m-num_drawn; 
        
        max_heap.push(max_avail);
    }
    
    cout<<m<<endl;
    while(m){
        max_avail = max_heap.top();
        max_heap.pop();
        
        //One ticket left
        cost += max_avail;
        --max_avail;
        m = m -1;
    }
    
    return cost;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<int> v = {2,5};
    cout<<maxCost(v,4);
    return 0;
}