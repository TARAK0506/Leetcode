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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
      map<int,int>mp;
      for(auto it:nums){
        mp[it]++;
      }
      ListNode* curr=new ListNode();
      ListNode* temp=curr;
      while(head!=NULL){
        if(mp.find(head->val) == mp.end()){
          temp->next=head;
          temp=temp->next;
        }
        head=head->next;
      }
      temp->next=NULL;
      return curr->next;
    }
};