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
class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
            ListNode*first=head;
            if(first==nullptr||first->next==nullptr)return head;
            ListNode*newhead=head;
            ListNode*second=first->next;
            ListNode*prev=nullptr;
            while(first!=nullptr&&second!=nullptr){
                if(prev!=nullptr)prev->next=second;
                else newhead=second;
                first->next=second->next;
                second->next=first;
                prev=first;
                first=first->next;
                if(first!=nullptr)second=first->next;
            }
            return newhead;
        }
    };