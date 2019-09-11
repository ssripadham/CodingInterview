#include <iostream>
#include <vector>

using namespace std;

void floodfill(vector<vector<int> & wall, int x, int y , int color){

	if (wall.empty()) return;

	if (x < 0 || x > wall.size()() return;
		if (y < 0 || y > wall[0].size()) return;
		
		for (int dx = -1; dx <=1 ; ++dx){
			for (int dy = -1; dy <= 1; ++dy){
				if (dx==0 && dy == 0) continue;
				floodfill(wall, x+dx, y+dy, color);
			}
		}
	}
	
	int main(){
		vector<vector<int> > wall[3][3];
		floodfill(wall,0,0,2); 
}