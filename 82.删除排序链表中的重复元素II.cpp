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
        ListNode* deleteDuplicates(ListNode* head) {
            ListNode*newHead=new ListNode(0,head);
            ListNode*prev=newHead;
            ListNode*current=head;
            while(current!=nullptr&&current->next!=nullptr){
                if(current->val==current->next->val){
                    int deleteVal=current->val;
                    while(current!=nullptr&&current->val==deleteVal){
                        prev->next=current->next;
                        delete current;
                        current=prev->next;
                    }

                }
                else{
                    prev=current;
                    current=current->next;
                }
            }
            return newHead->next;
            
        }
    };