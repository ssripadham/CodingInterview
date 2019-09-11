// You are asked to write a function called max_slice which takes as an input an array of integers, and returns the slice with the largest sum of the elements.

// 8, -7, 3, 2, 5 -> return whole array
// 

#include <iostream>
#include <utility>
#include <vector>
#include <climits>

using namespace std;

// To execute C++, please define "int main()"
vector<int> findLargestSlice(const vector<int> & v) {
   
  vector<int> output, result;
  
  int bestSumSoFar = 0;
  int maxEndingHere = 0;
  
  for (unsigned int i = 0; i <v.size(); ++i) {  
    
    maxEndingHere = maxEndingHere + v[i];
    output.push_back(v[i]);

    if (maxEndingHere < 0) {
      maxEndingHere = 0;
      output.clear();
    }

    if (maxEndingHere > bestSumSoFar) {
       bestSumSoFar = maxEndingHere;
       result.clear();
       copy(output.begin(), output.end(), std::back_inserter(result)); //check on vector copy
    }
  }
  
  return result;
}


int main() {
  
  std::vector<int> v = {-1,-9};
  //vector<int> v = { -1, -2 , 1 , 2};
  //vector<int> v = {-8, -7, -5};
  //vector<int> v = {8,-7,-3,-2,-5};
  // vector<int> v = {8,-7,3,2,5};
  // vector<int> v = {8,-9,3,2,5};
  // vector<int> v = {8,7,3,2,5};
  
  vector<int> output = findLargestSlice(v);
  
    
  for (unsigned int i = 0; i < output.size(); i++) {
    cout << output[i]<< " ";
  }
  cout<<endl;
  cout<<"finished";
  
  return 0;
}
