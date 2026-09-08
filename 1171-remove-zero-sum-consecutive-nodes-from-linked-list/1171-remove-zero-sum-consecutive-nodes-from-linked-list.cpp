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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> mp;
        ListNode* dummy = new ListNode(-10000);
        mp[0] = dummy;
        dummy->next = head;
        ListNode* curr = dummy;
        int prefixSum = 0;
        while (curr) {
            prefixSum += curr->val;
            if (mp.find(prefixSum) != mp.end()) {
                ListNode* prev = mp[prefixSum];
                ListNode* start = prev->next;
                ListNode* end = curr;
                int sum = prefixSum;
                while (start != end) {
                    sum += start->val;
                    mp.erase(sum);
                    start = start->next;
                }
                prev->next = curr->next;
            } else {
                mp[prefixSum] = curr;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};