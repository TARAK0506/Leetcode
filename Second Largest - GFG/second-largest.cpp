//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int print2largest(int arr[], int n) {
	    int largest=arr[0],slargest=-1;
	    for(int i=0;i<n;i++){
	        if(arr[i]>largest){
	            largest=arr[i];
	        }
	    }
	    for(int i=0;i<n;i++){
	        if(arr[i]>slargest && arr[i]!=largest){
	            slargest=arr[i];
	        }
	    }
	    return slargest;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends