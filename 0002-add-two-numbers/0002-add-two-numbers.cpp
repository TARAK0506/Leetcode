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
// ListNode* reverse(ListNode* original){
//     ListNode* prev=NULL,*temp=NULL;
//     ListNode* curr=original;
//     while(curr!=NULL){
//         temp=curr->next;
//         curr->next=prev;
//         prev=curr;
//         curr=temp;
//     }
//     return prev;
// }
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newnode = new ListNode();
        ListNode* temp = newnode;
        int carry=0,sum=0;
        while(l1!=NULL && l2!=NULL){
            int sum = carry + l1->val + l2->val;
            carry = (sum>=10)?1:0;
            sum=sum%10;
            ListNode* curr = new ListNode(sum);
            temp->next=curr;
            temp=temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL){
          int sum=l1->val+carry;
          carry = (sum>=10)?1:0;
          sum=sum%10;
          ListNode* curr=new ListNode(sum);
          temp->next=curr;
          temp=temp->next;
          l1=l1->next;
        }
        while(l2!=NULL){
          int sum=l2->val+carry;
          carry = (sum>=10)?1:0;
          sum=sum%10;
          ListNode* curr=new ListNode(sum);
          temp->next=curr;
          temp=temp->next;
          l2=l2->next;
        }
        if(carry!=0){
          ListNode* curr = new ListNode(carry);
          temp->next=curr;
          temp=temp->next;
        }
        return newnode->next;
    }
};