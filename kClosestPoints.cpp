/*
	Find k closest points to a given point
*/

#include <iostream>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;

typedef pair<int,int> Point;
typedef float Distance;

int findDistance(const Point & A, const Point & B) {
	double dx = A.first - B.first;
	double dy = A.second - B.second;
	sqrt(dx*dx + dy*dy);
}

int findKClosestPoints( const vector<Point> & v, const Point & refPt, int K){

	priority_queue< pair<Distance, Point>> pq;

	for (int i = 0; i < v.size(); ++i) {

		Point pt =v[i];
		Distance d = findDistance(pt, refPt);

		if (i < K){
			pq.emplace(d,pt);
		} else {

			if (d < pq.top().first) {
				pq.pop();
				pq.emplace(d,pt);
			}
		}

	}

}

int main(){

}
