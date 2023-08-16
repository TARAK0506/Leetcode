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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int cnt=0;
        while(temp!=nullptr){
            cnt++;
            temp=temp->next;
        }
        int pos=cnt-n;
        ListNode* newnode=new ListNode();
        ListNode* curr=newnode;
        ListNode* temp2=head;
        int count=0;
        while(temp2!=nullptr){
            if (count!=pos){
                curr->next=new ListNode(temp2->val);
                curr=curr->next;
            }
            temp2=temp2->next;
            count++;
        }
        return newnode->next;
    }
};