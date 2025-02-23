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
    private:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(): val(0), next(nullptr){}
        ListNode(int x): val(x), next(nullptr){}
        ListNode(int x, ListNode* next): val(x), next(next){}
    };

    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode*newhead=new ListNode(0,head);
            ListNode*current=newhead;
            for(int i=0;i<=n;i++)current=current->next;
            ListNode*pre=newhead;
            while(current!=nullptr){
                current=current->next;
                pre=pre->next;
            }
            ListNode* temp=pre->next;
            pre->next=pre->next->next;
            delete temp;
            return newhead->next;

        }
    };