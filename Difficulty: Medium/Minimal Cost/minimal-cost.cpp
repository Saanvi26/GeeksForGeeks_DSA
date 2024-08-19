//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int helper(int index,vector<int>& arr, int& k,vector<int>&dp){
      if(index==0) return 0;
      if(dp[index]!=-1) return dp[index];
      int minsteps=INT_MAX;
      int jump=INT_MAX;
      for(int j=1;j<=k;j++){
          if(index-j>=0)
          jump=helper(index-j,arr,k,dp)+abs(arr[index]-arr[index-j]);
          minsteps=min(minsteps,jump);
      }
      return dp[index]=minsteps;
      
  }
    int minimizeCost(vector<int>& arr, int& k) {
        vector<int>dp(arr.size()+1,-1);
        return helper(arr.size()-1,arr,k,dp);
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