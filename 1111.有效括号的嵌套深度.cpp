#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.length();
        int depth = 0;
        vector<int>answer(n, 0);
        vector<int>leftorright(n, 0);
        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                depth++;
                answer[i] = depth % 2;
            }
            else {
                answer[i] = depth % 2;
                depth--;
            }
        }
        return answer;
    }
};