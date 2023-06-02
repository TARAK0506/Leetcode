//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printDiamond(int n) {
        for(int i=0;i<n;i++){
            for(int spaces=0;spaces<n-i-1;spaces++){
                cout<<" ";
            }
            for(int stars=0;stars<=i;stars++){
                cout<<"* ";
            }
             for(int spaces=0;spaces<n-i-1;spaces++){
                cout<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<n;i++){
            for(int spaces=0;spaces<i;spaces++){
                cout<<" ";
            }
            for(int stars=0;stars<n-i;stars++){
                cout<<"* ";
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
        ob.printDiamond(n);
    }
    return 0;
}
// } Driver Code Ends