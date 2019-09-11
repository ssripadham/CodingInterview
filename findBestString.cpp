/*
	http://www.careercup.com/question?id=4855286160424960
*/
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

string findBest(const string & s, const string & t) {
	
	
	string best_str("");

	//We maintain the following two
	int max = INT_MIN; //Maximum span of sliding window
	priority_queue<int, vector<int>, greater<int>> min_heap; 
					//minimum of sliding window maintained in the top

	//Establish baseline sliding window
	for (int i = 0; i < t.length(); ++i){
		for (int j = 0; j < s.length(); ++j) {
			if (s[j] == t[i]) {
				min_heap.push(j); 
				if (j > max) max = j;
				break;
			}
		}
	}


	if (min_heap.size() != t.length()) return best_str;

	int index = min_heap.top();
	char elem = s[index];
	int best_dist = max - index + 1;
	best_str = s.substr(index, best_dist);
	
	//Keep looking for elem, lowest index character
	while (true) {

		index++;
	
		if (index == s.length()) break;
		
		if (s[index] == elem) {

			min_heap.pop();
			//Push the new position of elem
			min_heap.push(index);
			
			if (index > max) max = index;

			//New element to find
			index = min_heap.top();
			elem = s[index];

			//Update best results found so far
			if (max - min_heap.top() < best_dist){
				best_dist = max - index + 1;
				best_str  = s.substr(index, best_dist);
			}

		}

	}

	return best_str;

}

int main() {
	
	cout<<findBest("adobecodebanc", "abc");

}
