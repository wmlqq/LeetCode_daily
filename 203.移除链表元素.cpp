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
        ListNode* removeElements(ListNode* head, int val) {
            ListNode*newHead=new ListNode(0,head);
            ListNode*prev=newHead;
            ListNode*current=head;
            while(current!=nullptr){
                if(current->val==val){
                    ListNode*temp=current;
                    prev->next=current->next;
                    current=current->next;
                    delete temp;
                }
                else{
                    prev=prev->next;
                    current=current->next;
                }
            }
            return newHead->next;
        }
    };