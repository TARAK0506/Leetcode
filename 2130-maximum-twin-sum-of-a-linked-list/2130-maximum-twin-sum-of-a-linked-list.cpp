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
    int pairSum(ListNode* head) {
        int cnt=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            cnt++;
            temp=temp->next;
        }
        int n=cnt/2;
        int i=0;
        ListNode* slow=head;
        ListNode* fast=head;
        while(i<n){
            fast=fast->next;
            i++;
        }
        ListNode* prev=NULL;
        while(fast!=nullptr){
            ListNode* next=fast->next;
            fast->next=prev;
            prev=fast;
            fast=next;
        }
        int maxi=INT_MIN;
        fast=prev;
        while(slow!=nullptr && fast!=nullptr){
            int sum=slow->val+fast->val;
            slow=slow->next;
            fast=fast->next;
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};