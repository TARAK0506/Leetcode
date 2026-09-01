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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};
        if (!head || !head->next || !head->next->next)
            return ans;
        ListNode *prev = head, *curr = head->next, *nxt = curr->next;
        int idx = 1, first = -1, last = -1;
        int minDist = INT_MAX;
        while (nxt) {
            bool criticalPoint = (prev->val < curr->val && curr->val > nxt->val) || (prev->val > curr->val && curr->val < nxt->val);
            if (criticalPoint) {
                if (first == -1) {
                    first = idx;
                } else {
                    minDist = min(minDist, idx - last);
                }
                last = idx;
            }
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
            idx++;
        }
        if (first == -1 || first == last)
            return ans;
        ans[0] = minDist;
        ans[1] = last - first;
        return ans;
    }
};
