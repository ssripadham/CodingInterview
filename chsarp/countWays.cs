const int R = 3;
const int C = 3;

int countWays(int mat[][C], int row, int col,int k){
	
	if (row < 0 || col < 0) return 0;

	if (row == 0 && col == 0) {
		return (k-mat[row][col] == 0)? 1:0;
	}

	return countWays(mat, row-1, col, k - mat[row][col]) +
		countWays(mat, row, col-1, k - mat[row][col]);

}



// Driver program
int main()
{
    int k = 12;
    int mat[R][C] = { {1, 2, 3},
                      {4, 6, 5},
                      {3, 2, 1}
                  };
    cout << countWays(mat, R-1,C-1, k);
    return 0;
}