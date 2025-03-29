#include <vector>
#include <algorithm>
using namespace std;

// ����һ�����������
class Solution {
public:
    // ��������ͼ������ĳ���
    int longestCycle(vector<int>& edges) {
        // ��ȡ������ĳ��ȣ�Ҳ���ǽڵ������
        int n = edges.size();
        // ��ʼ������ĳ���Ϊ -1�����û�л��򷵻� -1
        int res = -1;
        // ���ڼ�¼ÿ���ڵ��Ƿ񱻷��ʹ��Լ����ʵ�ʱ���
        vector<int> visited(n, 0);
        // ��ǰ��ʱ�������ʼ��Ϊ 1
        int timeStamp = 1;

        // ����ÿ���ڵ�
        for (int i = 0; i < n; i++) {
            // �����ǰ�ڵ��Ѿ������ʹ���������
            if (visited[i]) continue;

            // ��¼���α�����ʼ��ʱ���
            int startTime = timeStamp;
            // �ӵ�ǰ�ڵ㿪ʼ����
            int cur = i;

            // ��ʼ���ű߽��б�����ֱ������ -1����ʾû�г��ߣ�
            while (cur != -1) {
                // �����ǰ�ڵ��Ѿ������ʹ�
                if (visited[cur]) {
                    // ���ýڵ��Ƿ��Ǳ��α����з��ʹ���
                    if (visited[cur] >= startTime) {
                        // ����ǣ�����㻷�ĳ��Ȳ���������ĳ���
                        res = max(res, timeStamp - visited[cur]);
                    }
                    // �����Ƿ��γɻ���������ѭ��
                    break;
                }
                // ��ǵ�ǰ�ڵ㱻���ʣ�����¼ʱ���
                visited[cur] = timeStamp++;
                // �ƶ�����һ���ڵ�
                cur = edges[cur];                
            }
        }
        // ��������ĳ���
        return res;
    }
};
