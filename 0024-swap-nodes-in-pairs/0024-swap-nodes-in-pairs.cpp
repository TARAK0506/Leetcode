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
    ListNode* swapPairs(ListNode* head) {
      ListNode* newnode=new ListNode(0);
      newnode->next=head;
      ListNode* curr=newnode;
      while(curr->next && curr->next->next){
        ListNode* s1=curr->next;
        ListNode* s2=curr->next->next;
        s1->next=s2->next;
        s2->next=s1;
        curr->next=s2;
        curr=s1;
      }
      return newnode->next;
    }
};