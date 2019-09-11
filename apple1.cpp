String (())
Result - true

String ()()
Result - true

())
false    

()((

(((((

#include <string>

using namespace std;

bool isBalanced(const std::string & str) {

    int num = 0;
    
    for (int i = 0; i < str.length(); ++i) {
        
        if (str[i] != '(' || str[i] != ')') continue;
        
        if (str[i] == '(') ++num;
        else --num;
        
        if (num < 0) return false;
        
    }
    

    return (num == 0);

} 
