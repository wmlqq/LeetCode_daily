struct ListNode{
        int val;
        ListNode* next;
        ListNode(): val(0), next(nullptr){}
        ListNode(int x): val(x), next(nullptr){}
        ListNode(int x, ListNode* next): val(x), next(next){}
    };
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<string>
using namespace std;
class Solution {
    public:
        int getDecimalValue(ListNode* head) {
            ListNode*current=head;
            string s="";
            while(current!=nullptr){
                s+=to_string(current->val);
                current=current->next;
            }
            return stoi(s,0,2);
        }
    };