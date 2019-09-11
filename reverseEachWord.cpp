
void Solution::reverseWords(string &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    string output;
    
    int i = 0;
    bool firstword = true;
    while (i < A.length()){
        
        while(isspace(A[i])){ i++; }
        
        if (i == A.length()) break;
        
        string word;
        while (i < A.length()){
            if (isspace(A[i])){
                i++;
                break;
            }
            word.push_back(A[i]);
            i++;
        }
        //word.push_back('\0');
        reverse(word.begin(), word.end());
        if (!firstword) output += ' ';
        output += word;
        firstword = false;
    }
    
    
    reverse(output.begin(), output.end());
    A = output;
}
