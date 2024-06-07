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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* l1=list1,*l2=list1;
      while(a>1){
        l1=l1->next;
        a--;
      }
      while(b>0){
        l2=l2->next;
        b--;
      }
      l1->next=list2;
      while(list2->next!=NULL){
        list2=list2->next;
      }
      list2->next=l2->next;
      return list1;
    }
};