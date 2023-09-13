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
ListNode* reverse(ListNode* & head){
  ListNode* curr=head;
  ListNode* prev=NULL;
  ListNode* temp=NULL;
  while(curr){
    temp=curr->next;
    curr->next=prev;
    prev=curr;
    curr=temp;
  }
  return prev;
}
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
      ListNode* l1=reverse(head);
      ListNode* newnode=new ListNode(0);
      ListNode* temp=newnode;
      int mul=0,carry=0;
      while(l1){
        mul=carry+(l1->val)*2;
        carry=(mul>=10)?1:0;
        mul=mul%10;
        ListNode* curr=new ListNode(mul);
        temp->next=curr;
        temp=curr;
        l1=l1->next;
      }
      if(carry!=0){
        ListNode* curr=new ListNode(carry);
        temp->next=curr;
        temp=curr;
      }
      return reverse(newnode->next);
    }
};