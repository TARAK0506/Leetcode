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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
       ListNode* curr=head;
        while(curr!=NULL && curr->next!=NULL) {
            int value = __gcd(curr->val,curr->next->val);
            ListNode* newnode=new ListNode(value);
            newnode->next=curr->next;
            curr->next=newnode;
            curr=newnode->next;
        }
        return head;
    }
};