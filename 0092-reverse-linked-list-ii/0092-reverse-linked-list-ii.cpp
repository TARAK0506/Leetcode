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
ListNode* reverseList(ListNode* start ,ListNode* end){
    ListNode* prev = NULL;
    ListNode* curr = start;
    ListNode* next = NULL;
    while (curr != end) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev; 
}

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL || left == right){
            return head;
        }
        ListNode* newnode = new ListNode(-1);
        newnode->next = head;
        ListNode* start = newnode;
        int l = left;
        while(l > 1){
            start = start->next;
            l--;
        }
        ListNode* end = start->next;
        int r = right - left + 1;
        while(r > 0){
            end = end->next;
            r--;
        }
        ListNode* reverseHead = reverseList(start->next, end);
        ListNode* tail = start->next;
        tail->next = end;
        start->next = reverseHead;
        return newnode->next;
    }
};
