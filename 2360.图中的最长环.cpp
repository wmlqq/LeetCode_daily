#include <vector>
#include <algorithm>
using namespace std;

// 定义一个解决方案类
class Solution {
public:
    // 计算有向图中最长环的长度
    int longestCycle(vector<int>& edges) {
        // 获取边数组的长度，也就是节点的数量
        int n = edges.size();
        // 初始化最长环的长度为 -1，如果没有环则返回 -1
        int res = -1;
        // 用于记录每个节点是否被访问过以及访问的时间戳
        vector<int> visited(n, 0);
        // 当前的时间戳，初始化为 1
        int timeStamp = 1;

        // 遍历每个节点
        for (int i = 0; i < n; i++) {
            // 如果当前节点已经被访问过，则跳过
            if (visited[i]) continue;

            // 记录本次遍历开始的时间戳
            int startTime = timeStamp;
            // 从当前节点开始遍历
            int cur = i;

            // 开始沿着边进行遍历，直到到达 -1（表示没有出边）
            while (cur != -1) {
                // 如果当前节点已经被访问过
                if (visited[cur]) {
                    // 检查该节点是否是本次遍历中访问过的
                    if (visited[cur] >= startTime) {
                        // 如果是，则计算环的长度并更新最长环的长度
                        res = max(res, timeStamp - visited[cur]);
                    }
                    // 无论是否形成环，都跳出循环
                    break;
                }
                // 标记当前节点被访问，并记录时间戳
                visited[cur] = timeStamp++;
                // 移动到下一个节点
                cur = edges[cur];                
            }
        }
        // 返回最长环的长度
        return res;
    }
};
