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
#include <vector>
#include<climits>
using namespace std;
class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            ListNode*current=new ListNode();
            ListNode* head=current;
            vector<bool>empty(lists.size(),false);
            for(int i=0;i<lists.size();i++){
                if(lists[i]==nullptr){
                    empty[i]=true;
                }
            }
            
            while(1){
                int min=INT_MAX;int index=-1;
                for(int i=0;i<lists.size();i++){
                    if(empty[i]){
                        continue;
                    }
                    if(lists[i]->val<min){
                        min=lists[i]->val;
                        index=i;
                    }

                }
                if(index==-1)break;

                current->next=lists[index];current=current->next;
                lists[index]=lists[index]->next;
                if(lists[index]==nullptr){
                    empty[index]=true;
                }

            }
            return head->next;

        }
    };