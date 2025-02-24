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
class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) {
            if(head==nullptr||head->next==nullptr||k==0){
                return head;
            }
            ListNode*newHead=new ListNode(0,head);
            ListNode*fast=head;
            ListNode*slow=head;
            int len=0;
            while(fast!=nullptr){
                len++;
                fast=fast->next;
            }
            k=k%len;
            fast=head;
            for(int i=0;i<k;i++){
                if(fast->next==nullptr){
                    fast=head;
                }
                else{
                    fast=fast->next;
                }
            }
            while(fast->next!=nullptr){
                fast=fast->next;
                slow=slow->next;
            }
            fast->next=head;
            newHead=slow->next;
            slow->next=nullptr;
            return newHead;

        }
    };