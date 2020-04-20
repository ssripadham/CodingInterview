#include <iostream>
#include <string>
#include <set>

using namespace std;

/*
                   1262
  
  1,262          12,62           *126,2
 i 
(1,2,62) (1,26,2)    12,6,2  12,62
(1,2,6,2)   (12,6,2)          12,6,2
  
  1  2 6 2
  1  1 1 1
  
*/

int decodeHelper(string strSoFar, string rest, set<string> & cache){
  
  //cout<<strSoFar<<" "<<rest<<endl;
  
  if (rest.empty()) return 1;
  
  if ( rest.length() == 1 && rest[0] != '0') {
    int num = stoi(rest);
    strSoFar += num -1 + 'A';
    cache.insert(strSoFar);
    return 1;
  }
  
  if (cache.find(strSoFar) != cache.end()) return 1;
  
  int count = 0;
  /* i = 1, 2  262*/
  for (int i = 0; i < rest.length(); ++i) {
    
    string firstNum = rest.substr(0,i);
    
    if ( !firtNum.empty()) {
    
    if (firstNum[0] == '0') continue;
    
      int num = std::stoi(firstNum);
    
      if (num > 26) break;
    
      strSoFar += num -1 + 'A';
    
    }
    
    string remaining = rest.substr(i);
    
    count += decodeHelper(strSoFar, remaining, cache);
    
  }
  
  return count;
}


int decodeVariations(const string& S)
{
  
  set<string> cache;
  return decodeHelper("",S, cache);
}

int main() 
{
  cout<<decodeVariations("26")<<endl;
	return 0;
}
