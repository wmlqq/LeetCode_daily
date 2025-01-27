#include<vector>
#include<string>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int result = 0;
        unordered_set<string>newwords(words.begin(), words.end());

        for (string word : words) {
            for (int i = 1; i < word.length(); i++) {
                newwords.erase(word.substr(i));
            }
        }

        for (string word : newwords)result += (word.length() + 1);
        return result;
    }
};