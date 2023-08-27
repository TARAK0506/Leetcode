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
ListNode* reverse(ListNode* head) {
    ListNode *curr = head, *prev = NULL,*temp=NULL;
    while (curr != NULL) {
        // swap(cur->next, prev);
        // swap(prev, cur);
      temp=curr->next;
      curr->next=prev;
      prev=curr;
      curr=temp;
    }
    return prev;
}
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
      head=reverse(head);
      ListNode* temp=head;
      while(temp!=NULL && temp->next!=NULL){
        if(temp->val > temp->next->val){
          temp->next=temp->next->next;
        }
        else
          temp=temp->next;
      }
      return reverse(head);
    }
};