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
    void reorderList(ListNode* head) {
      if((!head) || (!head->next) || (!head->next->next)){
        return ;
      }
      stack<ListNode*>st;
      ListNode* temp=head;
      int cnt=0;
      while(temp!=NULL){
        st.push(temp);
        cnt++;
        temp=temp->next;
      }
      ListNode* curr=head;
      for(int i=0;i<cnt/2;i++){
        ListNode* temp=st.top();
        st.pop();
        temp->next=curr->next;
        curr->next=temp;
        curr=curr->next->next;
      }
      curr->next=NULL;
    }
};