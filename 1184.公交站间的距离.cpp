#include<vector>
using namespace std;

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size();
        int current1=start,current2=start, distance1 = 0,distance2=0;

        while (1) {
            if (current1 != destination) {
                distance1 += distance[current1];
                current1 = (current1 + 1)%n;
            }
            if (current2 != destination) {
                current2 = (current2 + n - 1) % n;
                distance2 += distance[current2];
            }
            if (current1 == destination && current2 == destination)return min(distance1, distance2);
        }

    }
};