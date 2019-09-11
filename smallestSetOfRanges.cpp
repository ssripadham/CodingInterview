/*
http://www.careercup.com/question?id=6262661043978240
*/
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

struct Compare {
	bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
		if (a.first == b.first) return a.second < b.second;
		return a.first < b.first;
	}
};

vector<pair<int, int>> smallestSetOfRanges(vector<pair<int, int>>& ranges, pair<int, int> R) {
	vector<pair<int, int>> result;
	int target, i, maxTarget, maxIndex;
	bool match;

	if (R.first == R.second) {
		for (i = 0; i < ranges.size(); i++) {
			if (ranges[i].first <= R.first && ranges[i].second >= R.second) {
				result.push_back(ranges[i]);
				break;
			}
		}
		return result;
	}

	sort(ranges.begin(), ranges.end(), Compare());

	target = R.first;
	maxIndex = 0;
	while (target < R.second) {
		match = false;
		maxTarget = target;

		//loop to find Max traget
		for (i = maxIndex; i < ranges.size(); i++) {
			cout<<target<<" "<<maxTarget<<endl;
			/* ranges.first |target maxTarget| ranges.second */
			if (ranges[i].first <= target && ranges[i].second >= maxTarget) {
				match = true;
				maxTarget = ranges[i].second;
				maxIndex = i;
			} else if (ranges[i].first > target) {
				break;
			}
		}
		if (match == false) {
			result.clear();
			break;
		}
		result.push_back(ranges[maxIndex]);
		target = maxTarget;
		maxIndex++;
	}

	return result;
}

int main() {
	vector<pair<int,int>> s;
	s.push_back(make_pair(1, 2));
	s.push_back(make_pair(2, 3));
	s.push_back(make_pair(3, 4));
	s.push_back(make_pair(4, 5));
	s.push_back(make_pair(5, 6));
	s.push_back(make_pair(6, 7));
	s.push_back(make_pair(7, 8));
	s.push_back(make_pair(8, 9));
	s.push_back(make_pair(9, 10));
	s.push_back(make_pair(10, 11));
	pair<int,int> r = make_pair(1, 11);	
	vector<pair<int,int> > x = smallestSetOfRanges(s,r);

	for (int i = 0; i<x.size(); ++i){
		cout<<"("<<x[i].first<<","<<x[i].second<<")"<<endl;
	}
}