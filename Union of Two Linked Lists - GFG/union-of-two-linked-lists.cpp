//{ Driver Code Starts
#include<bits/stdc++.h>
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


// } Driver Code Ends
/*
// structure of the node is as follows

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
class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        // code here
        Node* temp=head1;
        map<int,bool>mp;
        while(temp){
            if(mp[temp->data]!=true){
                mp[temp->data]=true;
            }
            temp=temp->next;
        }
        Node* temp2=head2;
        while(temp2){
            if(mp[temp2->data]!=true){
                mp[temp2->data]=true;
            }
            temp2=temp2->next;
        }
        Node* newnode=new Node(0);
        Node* curr=newnode;
        for(auto it:mp){
            // cout<<it.first<<" "<<it.second<<endl;
            Node* temp=new Node(it.first);
            curr->next=temp;
            curr=curr->next;
        }
        return newnode->next;
    }
};


//{ Driver Code Starts.

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
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends