#include <iostream>
#include <vector>

#include <stack>
#include <climits>

using namespace std;

typedef vector< vector<int> > Grid;


int getMaxArea(vector<int> & histogram) {

	if (histogram.empty()) return -1;

	stack<int> stackOfIndices;
	
	int area = 0;
	int maxArea = INT_MIN;

	int i;
	for (i = 0; i < histogram.size(); ++i) {
		
		//Push as long as building height increases
		if (stackOfIndices.empty() || histogram[i] >= histogram[stackOfIndices.top()] )	{
			stackOfIndices.push(i);
		} else {
			//Pop as value is <= histogram[i] and compute area
			int topIndex = stackOfIndices.top();
			stackOfIndices.pop();
			area = stackOfIndices.empty()?histogram[topIndex]*i:histogram[topIndex]*(i-stackOfIndices.top()-1);
			maxArea = max(maxArea,area);		
		}
	}

	while (!stackOfIndices.empty()) {
		int topIndex = stackOfIndices.top();
		stackOfIndices.pop();
		area = stackOfIndices.empty()?histogram[topIndex]*i:histogram[topIndex]*(i-stackOfIndices.top()-1);
		maxArea = max(maxArea,area);		
	}

	return maxArea;
}

int maxSizeRectangle(Grid & g) {

	if (g.empty() || g[0].empty()) return -1;
	
	int numCol = g[0].size();
	
	vector<int> result(numCol);
	for (int col = 0; col < numCol; ++col)
		result[col] =g[0][col];

	int val = getMaxArea(result);

	for (int row = 1 ; row < g.size(); ++row) {
		for (int col = 0; col < numCol; ++col) {
			result[col] = (g[row][col] == 0) ? 0 : result[col]+1;
		val = std::max(val, getMaxArea(result));
		}
	}

	return val;
}

int main() {

	Grid g = { {1,0,0,1,1,1},
               {1,0,1,1,0,1},
               {0,1,1,1,1,1},
               {0,0,1,1,1,1}};
	cout<<maxSizeRectangle(g)<<endl;

	vector<int> v = {2,2,2,6,1,5,4,2,2,2,2};
    cout<<getMaxArea(v)<<endl;
}