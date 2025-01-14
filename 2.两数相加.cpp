#include <iostream>

using namespace std;

/*链表结构体
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
*/

// 添加节点
void addNode(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value);
    if (head == nullptr) {
        head = newNode; // 如果链表为空，设置头节点
    }
    else {
        ListNode* now = head;
        while (now->next != nullptr) {
            now = now->next;
        }
        now->next = newNode;
    }
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* addition = nullptr; // 结果链表的头节点
        int check = 0;

        while (l1 != nullptr || l2 != nullptr || check != 0) {
            int sum = check; // 从上一次的进位开始
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            check = sum / 10; // 计算新的进位
            addNode(addition, sum % 10); // 添加当前位的结果
        }

        return addition; // 返回结果链表的头节点
    }
};