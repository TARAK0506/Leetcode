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
    vector<int> nextLargerNodes(ListNode* head) {
      vector<int>vec;
      stack<int>st;
      ListNode* temp=head;
      while(temp!=NULL){
        vec.emplace_back(temp->val);
        temp=temp->next;
      }
      int n=vec.size();
      vector<int>ans(n,0);
      for(int i=vec.size()-1;i>=0;i--){
        while(!st.empty() && st.top()<=vec[i]){
          st.pop();
        }
        if(st.empty()==false){
          ans[i]=st.top();
        }
        st.push(vec[i]);
      }
      return ans;
    }
};