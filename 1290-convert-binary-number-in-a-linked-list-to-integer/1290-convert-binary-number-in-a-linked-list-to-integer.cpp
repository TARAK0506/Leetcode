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
        int decimal = 0;
        ListNode* curr = head;
        while (curr) {
            int bit = curr->val;
            decimal = decimal * 2 + (bit);
            curr = curr->next;
        }
        return decimal;
    }
};