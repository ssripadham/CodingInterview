//method
//it takes integer input n
//return true if n has integer sqrt, otherwise false
//n 16, 4 true
//7, 2.xx false
//not going to use sqrt lib


1 true
2 false

bool isPerfectSquare(int n) {

    int i = 1;
    
    while (true) {
    
        int mult = i*i;
        
        if (mult > n) return false;
    
        if (mult == n) return true;
        
        ++i;
    }
    
    return false;

}



bool isPerfectSquare2(int n){

    int low = 0;
    int high = n;
    
    while (high >= low) {
    
        int mid = low + (high-low)/2;
        
        int mult = mid*mid;
        
        if (mult == n) return true;
        

        if (mult < n) low = mid - 1;
        else high = mid+1;

    }
    
    return false;
}


//2B, 1,2,3,4 
//n 100, 


// a set of intervals
//(0,2) (-1, 3) (2,3) (15,21) (start, end)
//method that will merge these intervals if they are partially overlapped
// (-1,3) (15,21)


(-1 3) a (0 2) b (2 3)   (15 21)

typedef pair<int, int> Interval;

class Compare() {

    bool operator < (const Interval & a, const Interval & b) {
       return (a.first > b.first);
    }

}

stack<Interval> mergeIntervals(vector< pair<int, int> > & v) {
    
    sort(v.begin(), v.end(), Compare());
    
    stack<Interval> s;
    
    for (int i = 0; i < v.size() ++i) {
    
        Interval current = v[i];
        
        if ( i == 0 ) {
            s.push(current);
            continue;
        }
        
       
        Interval prev = s.top(); 
        
        if (current.first > prev.second) {
            //No overlap
            s.push(current);
        } else {
            //Merge current and prev, then push the result
            Interval mergedInterval = make_pair( std::min(prev.first, current.first), 
                                                 std::max(prev.second, current.second));
            s.pop(); //Pop previous
            s.push(mergedInterval);                                     
        }
        
    }

    return s;
        
}
        



}

