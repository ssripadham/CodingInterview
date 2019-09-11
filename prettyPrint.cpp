/*
Print concentric rectangular pattern in a 2d matrix. 
Let us show you some examples to clarify what we mean.

Example 1:

Input: A = 4.
Output:

4 4 4 4 4 4 4 
4 3 3 3 3 3 4 
4 3 2 2 2 3 4 
4 3 2 1 2 3 4 
4 3 2 2 2 3 4 
4 3 3 3 3 3 4 
4 4 4 4 4 4 4 
Example 2:

Input: A = 3.
Output:

3 3 3 3 3 
3 2 2 2 3 
3 2 1 2 3 
3 2 2 2 3 
3 3 3 3 3 
The outermost rectangle is formed by A, then the next outermost is formed by A-1 and so on.

You will be given A as an argument to the function you need to implement, and you need to return a 2D array.
*/


vector<vector<int> > Solution::prettyPrint(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int size = A*2 -1;
    
    vector<vector<int>> grid(size, vector<int>(size,0));
    
    int top = 0; 
    int bottom = size-1;
    int left = 0;
    int right = size -1;
    
    while (bottom >= top && right >= left){
        
        for (int c = left; c <= right; ++c)
            grid[top][c] = A;
        top = top+1;
        
        for (int r = top; r <= bottom; ++r)
            grid[r][right] = A;
        right = right - 1;
        
        for (int c = right; c >= left; --c)
            grid[bottom][c] = A;
        bottom = bottom - 1;
        
        for (int r = bottom; r >=top; --r)
            grid[r][left] = A;
        left = left + 1;
        
        A--;
    }
    
    return grid;
    
}
