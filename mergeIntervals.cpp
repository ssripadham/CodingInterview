/*

Given a set of time intervals in any order, merge all overlapping intervals into one and
output the result which should have only mutually exclusive intervals. 
Let the intervals be represented as pairs of integers for simplicity. 
For example, let the given set of intervals be {{1,3}, {2,4}, {5,7}, {6,8} }. 
The intervals {1,3} and {2,4} overlap with each other, so they should be merged and become {1, 4}. 
Similarly {5, 7} and {6, 8} should be merged and become {5, 8}

Write a function which produces the set of merged intervals for the given set of intervals.
*/
#include <iostream>
#include <utility>
#include <vector>
#include <stack>
#include <algorithm>
#include <iterator>

using namespace std;

typedef pair<int, int> Interval;

stack< Interval > mergeIntervals( const vector<Interval> & v) {

	stack<Interval> s;

	for (int i = 0; i < v.size(); ++i) {

		if (s.empty() || v[i].first > s.top().second) {
			s.push(v[i]);
		} else {

			Interval  top = s.top();
			s.pop();
			s.push(make_pair(std::min(top.first, v[i].first), std::max(top.second, v[i].second)));

		}


	}

	//vector<Interval> result;
	//copy(s.begin(),s.end(),result.begin());
	

	return s;
}

int main() {

	vector<Interval> v;
	v.push_back(make_pair(1,3));
	v.push_back(make_pair(2,4));
	v.push_back(make_pair(5,7));
	v.push_back(make_pair(6,8));

	stack<Interval> s = mergeIntervals(v);

	Interval top;
	while (!s.empty()){
		top = s.top();
		s.pop();
		cout<<"("<<top.first<<","<<top.second<<") ";
	}
	cout<<endl;
	//copy(v.begin(),v.end(),ostream_iterator(cout," "));

}
