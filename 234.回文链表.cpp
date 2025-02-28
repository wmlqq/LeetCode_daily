class Solution {
    public:
        bool isPalindrome(ListNode* head) {
            if (head == nullptr || head->next == nullptr) return true;
    
            ListNode* slow = head;
            ListNode* fast = head;
            while (fast != nullptr && fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
            }
    
            ListNode* prev = nullptr;
            while (slow != nullptr) {
                ListNode* temp = slow->next;
                slow->next = prev;
                prev = slow;
                slow = temp;
            }
    
            ListNode* left = head;
            ListNode* right = prev;
            while (right != nullptr) {
                if (left->val != right->val) return false;
                left = left->next;
                right = right->next;
            }
    
            return true;
        }
    };