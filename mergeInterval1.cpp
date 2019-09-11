#include <iostream>
#include <vector>
#include <stack>
#include <iterator>
#include <algorithm>

using namespace std;

 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    Interval compareInterval = Interval(std::min(newInterval.start, newInterval.end),
                                    std::max(newInterval.start, newInterval.end));
    
    stack<Interval> s;
    s.push(compareInterval);

    Interval currentInterval;
    for (int i=0; i<intervals.size(); ++i) {
    
        currentInterval = intervals[i];

        Interval stackTop = s.top();

        if (stackTop.end < currentInterval.start)
        {
            s.push(currentInterval);
        } else {

            if (currentInterval.end < stackTop.start) {
                s.pop();
                s.push(currentInterval);
                s.push(compareInterval);
            } else {

                s.pop();
                s.push(Interval(std::min(stackTop.start, currentInterval.start),
                        std::max(stackTop.end, currentInterval.end)) );
            }

        }

    }

    std::vector<Interval> output;

    
    while( !s.empty()){
        Interval elem = s.top(); s.pop();
        output.push_back(elem);
    }

    reverse(output.begin(), output.end());
    return output;
}

int main() {
    vector<Interval> v;
    v.push_back(Interval(3,5));
    v.push_back(Interval(7,9));
    Interval i(1,10);
    vector<Interval> output = insert(v,i);

    //copy(output.begin(), output.end(), ostream_iterator<Interval>(cout," "))
}