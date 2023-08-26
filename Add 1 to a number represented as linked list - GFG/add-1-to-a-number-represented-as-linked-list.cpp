//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/
Node* reverse(Node* reversed){
    Node* curr=reversed;
    Node* prev=NULL;
    Node* temp=NULL;
    while(curr!=NULL){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}
class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        head=reverse(head);
        Node* curr=head;
        Node* newnode=new Node(0);
        Node* temp=newnode;
        int sum=0,carry=1;
        while(curr!=NULL){
            sum=carry+curr->data;
            carry=(sum>=10)? 1:0;
            sum=sum%10;
            Node* cur=new Node(sum);
            temp->next=cur;
            temp=cur;
            curr=curr->next;
        }
        if(carry!=0){
            Node* cur=new Node(carry);
            temp->next=cur;
            temp=cur;
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
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends