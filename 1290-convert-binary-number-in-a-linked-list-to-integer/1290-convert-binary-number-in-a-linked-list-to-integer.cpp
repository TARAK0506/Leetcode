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
    int getDecimalValue(ListNode* head) {
        ListNode* curr=head;
        vector<int>ans;
        while(curr!=NULL){
            ans.emplace_back(curr->val);
            curr=curr->next;
        }
        reverse(ans.begin(),ans.end());
        int i=0,sol=0;
        for(auto it:ans){
            sol+=powl(2,i)*it;
            i++;
        }
        return sol;
    }
};