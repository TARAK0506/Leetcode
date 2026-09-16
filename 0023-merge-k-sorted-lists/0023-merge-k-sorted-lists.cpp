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
    ListNode* merge2Lists(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2)
            return nullptr;
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;
        ListNode *l1 = list1, *l2 = list2;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if (l1) {
            curr->next = l1;
        }
        if (l2) {
            curr->next = l2;
        }
        ListNode* res = dummyNode->next;
        delete dummyNode;
        return res;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = nullptr;
        for (int i = 0; i < lists.size(); i++) {
            head = merge2Lists(head, lists[i]);
        }
        return head;
    }
};