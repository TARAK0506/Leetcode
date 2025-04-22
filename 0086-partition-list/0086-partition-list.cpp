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
    ListNode* partition(ListNode* head, int x) {
        ListNode* l1 = new ListNode(-1);
        ListNode* l2 = new ListNode(-1);
        ListNode* dummylist1 = l1;
        ListNode* dummylist2 = l2;
        ListNode* temp = head;
        while (temp) {
            if (temp->val < x) {
                dummylist1->next = temp;
                dummylist1 = dummylist1->next;
            } else {
                dummylist2->next = temp;
                dummylist2 = dummylist2->next;
            }
            temp = temp->next;
        }
        dummylist2->next = nullptr;
        dummylist1->next = l2->next;
        return l1->next;
    }
};