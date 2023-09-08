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
    ListNode* insertionSortList(ListNode* head) {
      ListNode* temp=head;
      priority_queue<int,vector<int>,greater<int>>pq;
      while(temp){
        pq.push(temp->val);
        temp=temp->next;
      }
      ListNode* newnode=new ListNode(0);
      ListNode* curr=newnode;
      while(!pq.empty()){
        ListNode* newnode=new ListNode(pq.top());
        curr->next=newnode;
        curr=curr->next;
        pq.pop();
      }
      return newnode->next;
    }
};