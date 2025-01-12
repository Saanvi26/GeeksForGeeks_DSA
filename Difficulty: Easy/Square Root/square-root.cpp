//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        int low=1;
        int high=n;
        int num=n;
        int ans=INT_MIN;
        while(low<= high){
            int mid=low+(high-low)/2;
            int x=mid*mid;
            if(x==num) return mid;
            else if(x > num) high=mid-1;
            else {
                ans=max(ans,mid);
                low=mid+1;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends