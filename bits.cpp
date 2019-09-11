#include <iostream>
#include <vector>

using namespace std;

int main() {

  vector<string> v;
  v.push_back("apple");  
  v.push_back("peach");
  v.push_back("banana");
  v.push_back("mango");
  v.push_back("orange");

  int n1 = v.size();
  
  cout<<"All subsets using bits"<<endl;
  //i goes from 0 to 2^n - 1
  for (int i = 0 ; i < (1 << n1); ++i) {
    string output("");
    // j goes through n bits and checks i for the j th bit set
    for (int j = 0 ; j < n1; j++) {
      if ( (i & (1<<j)) > 0) {
        //cout<<"adding "<<v[j]<<endl;
        output += v[j]+" ";
      }
    }
    cout<<output<<endl;
  }

    cout<<endl;
    cout<<"*********************************"<<endl;

}