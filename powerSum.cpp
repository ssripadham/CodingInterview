#include <iostream>
#include <cmath>

using namespace std;


int powerSumUtil(int X, int N, int num)
{
	if (X < 0) return 0;

	if (X == 0) {
		return 1;
	}

	return powerSumUtil(X, N, num++) + powerSumUtil(X - pow(num,N), N, num++);
}

int powerSum(int X, int N) {
	
	return powerSumUtil(X, N, 1);

}

int main() {
	cout<<"powersum: "<<powerSum(13,2)<<endl;
	return 0;
}