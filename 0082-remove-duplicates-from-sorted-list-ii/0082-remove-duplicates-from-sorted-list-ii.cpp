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
      ListNode* prev=NULL;
      ListNode* temp=head;
      ListNode* newnode=new ListNode(0);
      ListNode* curr=newnode;
      while(temp){
        if(temp->next && temp->val==temp->next->val){
          while(temp->next && temp->val == temp->next->val){
            temp=temp->next;
          }
          curr->next=temp->next;
        }
        else{
          curr->next=temp;
          curr=curr->next;
        }
        temp=temp->next;
      }
      return newnode->next;
    }
};