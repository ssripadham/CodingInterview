
// [9, -9, 5, 4, 0] 0
/*[

   [9.-9]
   [9, -9, 0]
   
   
               9 -9 5
    
   9, {-9,5}        0 {-9,5}
   
   
 0, {5}  9{5}       -9 {5}  0 {5}
*/
#include <iostream>
  
#include <vector>
#include <iterator>
  
using namespace std;

// To execute C++, please define "int main()"
  
class Solution {
    
  public:
  
  Solution() {};
  ~Solution() {};
  vector< vector <int> > resultSet;
  
  void findSubSetHelper( const vector<int> & v, int sum, int index, vector<int> output) {

    //Base Case
    if (index > v.size()) {
      return;
    }

    if (sum == 0 && !output.empty() && index == v.size()) {
      //Add the output vector to results
      resultSet.push_back(output);
      return;
    }
  
    findSubSetHelper(v, sum, index+1, output);

    output.push_back(v[index]);
    findSubSetHelper(v, sum - v[index], index+1, output);
    return;
  }
  

  void findSubSet( const vector<int> & v, int sum) {
  
    vector<int> output;
    findSubSetHelper(v,sum, 0, output);
  }

};


void findSubSetByBits(const vector<int> & v, int K){

  int N = v.size();
  std::vector< std::vector<int> > resultSet;
  for (int i = 0; i < (1<<N); ++i) {
    std::vector<int> output;
    int sum = 0;
    for (int j = 0; j < N;  ++j) {

      if (i & (1<<j)){
        sum += v[j];
        output.push_back(v[j]);
      }

    }

    if (sum == K) {
      //copy(output.begin(),output.end(), ostream_iterator<int>(cout," ")); cout<<endl;
      resultSet.push_back(output);
    }
  }

 for (int i = 0; i < resultSet.size(); ++i) {
    vector<int> result = resultSet[i];
    copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));cout<<endl;    
  }   


}


 
int main() {
    
  vector<int> v = { 9, -9, 5, 4, 0};

  Solution s;
  int sum = 0;  
  
  s.findSubSet(v, 0);

  for (int i = 0; i < s.resultSet.size(); ++i) {
    vector<int> result = s.resultSet[i];
    copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));cout<<endl;    
  } 
  
  cout << "*********" <<endl;
  findSubSetByBits(v,0);

  return 0;
}
