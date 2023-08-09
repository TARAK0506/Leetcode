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
        ListNode* curr=head;
        // cout<<curr<<endl;
        if(head==NULL){
            return NULL;
        }
        while(curr->next!=NULL){
            // cout<<curr->val<<" "<<curr->next<<" ";
            if(curr->val==curr->next->val){
                curr->next=curr->next->next;
            }
            else
                curr=curr->next;
        }
        return head;
    }
};