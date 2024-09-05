//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int helper(vector<int>& height, int n,int index,vector<int>&dp){
        if(index>=(n-1)) return 0;
        if(dp[index]!=-1) return dp[index];
        int one=abs(height[index]-height[index+1])+helper(height,n,index+1,dp);
        int two=INT_MAX;
        if(index+2<n)
        two=abs(height[index]-height[index+2])+helper(height,n,index+2,dp);
        return dp[index]=min(one,two);
    }
    int minimumEnergy(vector<int>& height, int n) {
        int index=0;
        vector<int>dp(n+1,-1);
        return helper(height,n,index,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends