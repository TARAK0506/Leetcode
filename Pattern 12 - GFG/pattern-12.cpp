//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        for(int i=1;i<=n;i++){
            for(int numbers=1;numbers<=i;numbers++){
                cout<<numbers<<" ";
            }
            for(int spaces=1;spaces<=4*(n-i);spaces++){
                cout<<" ";
            }
            for(int reverse=i;reverse>=1;reverse--){
                cout<<reverse<<" ";
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