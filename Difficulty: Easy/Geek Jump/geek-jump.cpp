//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int helper(int indx,vector<int>&height,vector<int>&dp){
      if(indx==0) return 0;
      if(dp[indx]!=-1) return dp[indx];
      int right=INT_MAX;
      int left=abs(height[indx]-height[indx-1])+helper(indx-1,height,dp);
      if(indx>1)
      right=abs(height[indx]-height[indx-2])+helper(indx-2,height,dp);
      return dp[indx]=min(left,right);
  }
    int minimumEnergy(vector<int>& height, int n) {
        vector<int>dp(n+1,-1);
        return helper(n-1,height,dp);
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