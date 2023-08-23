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
    ListNode* deleteMiddle(ListNode* head) {
      ListNode* slow=head;
      ListNode* fast=head;
      ListNode* prev=NULL;
      if(head==NULL){
        return head;
      }
      while(fast!=NULL && fast->next!=NULL){
        prev=slow;
        // cout<<prev->val<<" "<<prev->next<<endl;
        slow=slow->next;
        fast=fast->next->next;
      }
      if(prev==NULL){
        return NULL;
      }
      prev=prev->next;
      ListNode* temp=head;
      while(temp!=NULL){
        if(prev==temp->next){
          temp->next=temp->next->next;
        }
        temp=temp->next;
      }
      return head;
    }
};