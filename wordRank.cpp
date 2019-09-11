#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool recPermute(string strSoFar, string rest, const string & given,int & rank, unordered_set<string> & myset) {
    
    if (rest.empty()) {
        //cout<<strSoFar<<endl;
        if (strSoFar == given) { cout << rank << endl; return true; }
        if ( myset.find(strSoFar) == myset.end()) { 
            myset.insert(strSoFar);          
            rank += 1;
        }
    } else {
        for (int i = 0; i<rest.length();++i) {
            string rem = rest.substr(0,i)+ rest.substr(i+1);
            if (recPermute(strSoFar+rest[i],rem,given,rank, myset)) return true;
        }
    }
    
    return false;
}
/*
void RecPermute(string soFar, string rest)
{
    if (rest.empty()) {
        cout << soFar << endl;
    } else {
    for (int i = 0; i < rest.length(); i++) {
        string remaining = rest.substr(0, i)
            + rest.substr(i+1);
        RecPermute(soFar + rest[i], remaining);
    }
}
*/

/*
 * Complete the function below.
 */
vector < int > get_ranks(vector < string > words) {

    
    vector<int> output;
    unordered_set<string> myset;
    for (int i = 0; i< words.size();++i) {
        int rank = 0;    
        string str(words[i]);
        sort(str.begin(), str.end());
        recPermute("",str,words[i],rank, myset);
        //cout<<rank<<endl;
        output.push_back(rank);
    }
  
    return output;
}



int main(){
    int rank = 0;
    vector<string> words = { "bac", "aaa", "abba"};
    get_ranks(words);
    /*
    string str("bac");
    sort(str.begin(),str.end());cout<<str<<endl;
    recPermute("","abc", "bac",rank);
    cout<<rank<<endl;
    //cout<<RecPermute("abc","");*/
}