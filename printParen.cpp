#include <iostream>

using namespace std;

void printParen(string inputStr, int numLeftRemaining, int numRightRemaining){
	
	if (numLeftRemaining == 0 && numRightRemaining == 0){
		cout << inputStr <<endl;
	}

	if (numLeftRemaining > 0){
		printParen(inputStr+"(", numLeftRemaining - 1, numRightRemaining);
	}

	if (numRightRemaining > 0 && numRightRemaining >numLeftRemaining){
		printParen(inputStr+")", numLeftRemaining, numRightRemaining - 1);
	}
}

int main() {
	printParen("", 3, 3);
	return 1;
}