/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

Example:

Input: 
words = ["oath","pea","eat","rain"] and board =
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]

Output: ["eat","oath"]
Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/
class Solution {
public:
    bool findUtil(vector<vector<char>> & board, const string & word, int index, 
                  int row, int col, 
                  int numRows, int numCols, vector<vector<bool>> & visited){
      
        if (index == word.length()){
            return true;
        }
        //cout<<row<<" "<<col<<endl;
        
        if (row < 0 || row >= numRows || col < 0 || col >= numCols || visited[row][col]) return false;
        
        if (board[row][col] == word[index]){
            
            visited[row][col] = true;
            
            if ( findUtil(board, word, index+1, row-1, col, numRows, numCols, visited) ||
                 findUtil(board, word, index+1, row+1, col, numRows, numCols, visited) ||
                 findUtil(board, word, index+1, row, col-1, numRows, numCols, visited) ||
                 findUtil(board, word, index+1, row, col+1, numRows, numCols, visited) ) {
                return true;
            }
            
            visited[row][col] = false;
        }
            
        return false;
    }
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        int numRows = board.size();
        int numCols = board[0].size();
        
        set<string> oSet;
        for (int i = 0; i < words.size(); ++i){
            vector<vector<bool> > visited(numRows,vector<bool>(numRows, false));
            for (int row = 0; row < numRows; ++row){
                for (int col = 0; col < numCols; ++col){
                    if (board[row][col] == words[i][0]){
                        //visited[row][col] = true;
                        if (findUtil(board, words[i], 0, row, col, numRows, numCols, visited)){
                            //output.push_back(words[i]);
                            oSet.insert(words[i]);
                        }
                    }
                }
            }
        }

        
        std::vector<string> output(oSet.size());
        copy(oSet.begin(), oSet.end(), output.begin());
        return output;
        
    }
};