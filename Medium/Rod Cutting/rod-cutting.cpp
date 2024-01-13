//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution{
    private:
    int maxprofit(int price[],int arr[],int idx,int n,vector<vector<int>>&dp){
        if(n==0){
            return 0;
        }
        if(dp[idx][n]!=-1){
            return dp[idx][n];
        }
        if(idx<=n){
             dp[idx][n]=max(price[idx-1]+maxprofit(price,arr,idx,n-arr[idx-1],dp),maxprofit(price,arr,idx+1,n,dp));
             return dp[idx][n];
        }
         dp[idx][n]=0;
         return dp[idx][n];
    }
  public:
    int cutRod(int price[], int n) {
        int arr[n];
        for(int i=0;i<n;i++){
            arr[i]=i+1;
        }
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        return maxprofit(price,arr,1,n,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends