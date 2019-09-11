#include <iostream>
#include <set> //Constant time lookup

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,k;
    scanf("%d %d",&N,&k);
    
    set<int> s;
    while (N--){
        int val;
        cin>>val;
        //Assume no duplicates
        s.insert(val);   
    }
    
    int count = 0;
    for (auto iter = s.begin(); iter != s.end(); ++iter) {
 
        int num = (*iter) -k;
        auto miter = s.find(num);
        
        if (miter != s.end()) ++count;
    }
    
    cout<<count<<endl;
    
    return 0;
}