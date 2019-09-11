/* 
 * Program to compute the number of different ways to exactly represent
 * an arbitrary value less than $1,000,000 using any number or combination
 * of the following US denominations.
 * $100, $50, $20, $10, $5, $1, $0.25, $0.10, $0.05 and $0.01. 
 *  
 * Author : Sudharsan Sripadham 
 * Date   : 01/26/2013 
 *  
 * Usage: make_change <value in USD> 
 */


//includes
#include <iostream>
#include <limits.h>
#include <map>
#include <sstream>

//namespace
using namespace std;


//
// make_change computes number of combinations using dynamic programming
//
unsigned long long make_change(int* denom, unsigned int n, int sum) {

    map<int, unsigned long long> dp;
    
    dp[0] = 1;
    
    
    for (unsigned int i = 1 ; i <= sum ; ++i) {
        dp[i] = 0;
    }
    

    for (unsigned int i = 0; i < n; ++i) {
        for (unsigned int j = denom[i]; j <= sum; ++j) {	//

            //
            // Optimization: Sub problem will only depend on
            // sum-v[i]
			//
			if (sum > 10001) {
			 dp.erase(sum - 10001);
			}


            dp[j] += dp[j-denom[i]];
        }
    }
    
    return dp[sum];
}


//
// main function
//
int main( int argc, char* argv[]) {

    if (argc < 2) {
        cout<<"Incorrect Usage: make_change <value in USD> !!!"<<endl;
        return 0;
    }

    //
    // Convert input value to integer
    //
    istringstream ss(argv[1]);

    int value ;
    if (!(ss >> value)) {
        return 0;
    }

    //
    // Compute combinations
    //
    int denomination[10] = {1, 5, 10, 25, 100, 500, 1000 , 2000, 5000, 10000 };
    cout<< " You can make change for "<< value*100 << " in " 
        << make_change(denomination,10,value) 
        << " different way(s)." << endl ;
    
    return 1;
}