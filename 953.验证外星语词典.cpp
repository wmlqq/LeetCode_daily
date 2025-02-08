#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // 创建字符映射表
        vector<int> alphabet(26);
        for (int i = 0; i < order.length(); i++) {
            alphabet[order[i] - 'a'] = i;
        }

        // 直接比较相邻的单词
        for (int i = 0; i < words.size() - 1; i++) {
            if (!compareWords(words[i], words[i + 1], alphabet)) {
                return false;
            }
        }
        return true;
    }

private:
    bool compareWords(string& w1, string& w2, vector<int>& alphabet) {
        int len = min(w1.length(), w2.length());
        for (int i = 0; i < len; i++) {
            if (alphabet[w1[i] - 'a'] < alphabet[w2[i] - 'a']) return true;
            if (alphabet[w1[i] - 'a'] > alphabet[w2[i] - 'a']) return false;
        }
        return w1.length() <= w2.length();
    }
};