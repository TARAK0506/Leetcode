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
ListNode* reverse(ListNode* tobereversedlist){
  ListNode* temp=tobereversedlist;
  ListNode* prev=NULL;
  ListNode* curr=NULL;
  while(temp!=NULL){
    curr=temp->next;
    temp->next=prev;
    prev=temp;
    temp=curr;
  }
  return prev;
}
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      l1=reverse(l1);
      l2=reverse(l2);
      ListNode* newnode = new ListNode(0);
      ListNode* temp = newnode;
      int sum=0,carry=0;
      while(l1!=NULL && l2!=NULL){
        sum=carry+l1->val+l2->val;
        carry=(sum>=10)? 1:0;
        sum=sum%10;
        ListNode * curr=new ListNode(sum);
        temp->next=curr;
        temp=curr;
        l1=l1->next;
        l2=l2->next;
      }
      while(l1!=NULL)
      {
        sum=carry+l1->val;
        carry=(sum>=10)? 1:0;
        sum=sum%10;
        ListNode * curr=new ListNode(sum);
        temp->next=curr;
        temp=curr;
        l1=l1->next;
      }
      while(l2!=NULL)
      {
        sum=carry+l2->val;
        carry=(sum>=10)? 1:0;
        sum=sum%10;
        ListNode * curr=new ListNode(sum);
        temp->next=curr;
        temp=curr;
        l2=l2->next;
      }
      if(carry!=0){
        ListNode* curr=new ListNode(carry);
        temp->next=curr;
        temp=curr;
      }
      return reverse(newnode->next);
    }
};