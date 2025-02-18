#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class RangeFreqQuery {
public:
    RangeFreqQuery(vector<int>& arr) {
        this->arr = arr;
        for (int i = 0; i < arr.size(); i++) {
            map[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) {
        if (map.find(value) == map.end())return 0;
        const vector<int>&index = map[value];
        return upper_bound(index.begin(), index.end(), right) - lower_bound(index.begin(), index.end(), left);
    }

private:
    vector<int> arr;
    unordered_map<int, vector<int>> map;

};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */