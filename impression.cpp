/*
Impression - ID (PK), timestamp, cost
Click - TimeStamp, ImpressionID (FK)

How much I am spending on the clicks?


ClickEvent -> Click from WebPage/ Phone etc
Redirection


1. Impressions one Ad/ couple of seconds
2. One cost per impression
*/


#include <map>
#include <algorithm>

#include <vector>
#include <iostream>

using namespace std;



class Impression
{
public:
//	Impression();
	//~Impression() {};

	long long ID;

	int timestamp;
	double cost;
};

class ClickEvent {
public:
	int timeStamp;
	long long ID;
};

class ImpressionManager {

public:
	map<long long, Impression> impressionMap;
};

ImpressionManager iManager;

double ComputeCost(vector<ClickEvent> clickEvents){

	double retVal = 0;
	for (int i = 0; i < clickEvents.size(); ++ i){

		ClickEvent c = clickEvents[i];

		auto impressionIter = iManager.impressionMap.find(c.ID);
		if (impressionIter != iManager.impressionMap.end() ) {
			 Impression imp = (*impressionIter).second;

			 retVal += imp.cost;
		}
	}

	return retVal;

}

int main() {

	Impression i1;
	i1.ID = 1;
	i1.cost = 5.0;

	Impression i2;
	i2.ID = 2;
	i2.cost = 7.0;

	ClickEvent c1;
	c1.ID = 2;

	ClickEvent c2;
	c2.ID = 1;


    iManager.impressionMap[i1.ID] = i1;
    iManager.impressionMap[i2.ID] = i2;

	std::vector<ClickEvent> v1;
	v1.push_back(c1);
	v1.push_back(c2);

	cout<<ComputeCost(v1)<<endl;



}

