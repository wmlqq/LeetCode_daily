class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            ListNode*current=head;
            while(current!=nullptr&&current->next!=nullptr){
                if(current->next->val==current->val){
                    ListNode*temp=current->next;
                    current->next=current->next->next;
                    delete temp;
                }
                else current=current->next;
            }
            return head;
        }
    };