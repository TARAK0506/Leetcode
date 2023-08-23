//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* reverse(struct Node* original){
        Node* prev=NULL;
        Node* temp=NULL;
        Node* curr=original;
        while(curr!=NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first=reverse(first);
        second=reverse(second);
        Node* newnode=new Node(0);
        Node* temp=newnode;
        int sum=0,carry=0;
        while(first!=NULL && second!=NULL){
            sum=carry + first->data + second->data;
            carry=(sum>=10) ? 1:0;
            sum=sum%10;
            Node* curr=new Node(sum);
            temp->next=curr;
            temp=temp->next;
            first=first->next;
            second=second->next;
        }
        while(first!=NULL){
          int sum=first->data+carry;
          carry = (sum>=10)?1:0;
          sum=sum%10;
          Node* curr=new Node(sum);
          temp->next=curr;
          temp=temp->next;
          first=first->next;
        }
        while(second!=NULL){
          int sum=second->data+carry;
          carry = (sum>=10)?1:0;
          sum=sum%10;
          Node* curr=new Node(sum);
          temp->next=curr;
          temp=temp->next;
          second=second->next;
        }
        if(carry!=0){
          Node* curr = new Node(carry);
          temp->next=curr;
          temp=temp->next;
        }
        return reverse(newnode->next);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends