#include<vector>
#include<string>
#include<unordered_map>
#include<set>
#include<utility>
using namespace std;
class FoodRatings {
    private:
        unordered_map<string, pair<int,string>> foodMap;
        unordered_map<string,set<pair<int,string>>>cuisineMap;

    public:
        FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
            int n=foods.size();
            for(int i=0;i<n;i++){
                foodMap[foods[i]]={ratings[i],cuisines[i]};
                cuisineMap[cuisines[i]].emplace(-ratings[i],foods[i]);//set会自动弱排序
            }
        }
        
        void changeRating(string food, int newRating) {
            cuisineMap[foodMap[food].second].erase({-foodMap[food].first,food});
            foodMap[food].first=newRating;
            cuisineMap[foodMap[food].second].emplace(-newRating,food);
        }
        
        string highestRated(string cuisine) {
            return cuisineMap[cuisine].begin()->second;
        }
    };
    
    /**
     * Your FoodRatings object will be instantiated and called as such:
     * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
     * obj->changeRating(food,newRating);
     * string param_2 = obj->highestRated(cuisine);
     */