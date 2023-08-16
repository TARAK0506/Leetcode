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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp=head;
        int cnt=0;
        while(temp!=nullptr){
            cnt++;
            temp=temp->next;
        }
        temp=head;
        ListNode* left=head;
        ListNode* right=head;
        int count=1;
        while(count!=k){
            left=left->next;
            count++;
        }
        count=1;
        while(count!=cnt-k+1){
            right=right->next;
            count++;
        }
        swap(left->val,right->val);
        return head;
    }
};