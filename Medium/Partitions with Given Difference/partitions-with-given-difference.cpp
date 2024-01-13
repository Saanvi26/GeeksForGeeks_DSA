//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
        int mod=1e9+7;
    private :
    int CountofSubsetsWithGivenSum(int arr[],int n,int sum,vector<vector<int>>&dp){
         if(n==0){
             return sum==0;
         }
         if(dp[n][sum]!=-1){
             return dp[n][sum];
         }
        if(arr[0]<=sum){
         return dp[n][sum]=(CountofSubsetsWithGivenSum(arr+1,n-1,sum-arr[0],dp) % mod +
          CountofSubsetsWithGivenSum(arr+1,n-1,sum,dp) %mod) %mod;
        }
       return dp[n][sum]=CountofSubsetsWithGivenSum(arr+1,n-1,sum,dp)%mod;
    } 
    public:
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum=0;
        int a[arr.size()];
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            a[i]=arr[i];
        }
        int s=((sum+d)/2) % mod;
        if((sum+d)%2!=0){
            return 0;
        }
        vector<vector<int>> dp(n + 1,vector<int>(s + 1,-1));
         int ans2=CountofSubsetsWithGivenSum(a,n,s,dp);
         return ans2 % mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends