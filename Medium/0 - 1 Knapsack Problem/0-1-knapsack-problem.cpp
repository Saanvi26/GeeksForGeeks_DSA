//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    //1 2 3             4<=4           
    //4 5 1.   W=4.     dp[0]=max(1,
//dp -1 -1 -1 -1        
    private :
    int helper(int W, int wt[], int val[], int n,vector<vector<int>>&dp,int idx){
       if(n==0 || W==0){
          return 0;
      }
      if(dp[n][W]!=-1){
          return dp[n][W];
      }
      if(wt[0]<=W){
      dp[n][W]=max(val[0]+helper(W-wt[0],wt+1,val+1,n-1,dp,idx+1),helper(W,wt+1,val+1,n-1,dp,idx+1));
      return dp[n][W];
      }
      else{
      dp[n][W]=helper(W,wt+1,val+1,n-1,dp,idx+1);
      return dp[n][W];
      }
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
     vector<vector<int>>dp(n+1, vector<int>(W+1, -1));
     return helper(W,wt,val,n,dp,0);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends