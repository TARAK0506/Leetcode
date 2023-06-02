//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
	
	void printTriangle(int n) {
	    // code here
	    for(int i=0;i<n;i++){
	        for(int spaces=0;spaces<i;spaces++){
	            cout<<" ";
	        }
	        for(int stars=0;stars<2*n-(2*i+1);stars++){
	            cout<<"*";
	        }
	         for(int spaces=0;spaces<i;spaces++){
	            cout<<" ";
	        }
	        cout<<endl;
	    }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends