//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int helper(vector<int>& height, int n,int index,int k,vector<int>&dp){
        if(index>=(n-1)) return 0;
        int ans=INT_MAX;
        if(dp[index]!=-1) return dp[index];
        for(int i=1;i<=k;i++){
         int term=INT_MAX; 
        if(index+i<n)
        term=abs(height[index]-height[index+i])+helper(height,n,index+i,k,dp);
        ans=min(ans,term);
    }
        return dp[index]=ans;
}
    int minimizeCost(vector<int>& arr, int& k) {
        vector<int>dp(arr.size()+1,-1);
       return helper(arr,arr.size(),0,k,dp);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(arr, k);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends