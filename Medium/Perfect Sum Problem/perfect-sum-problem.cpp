//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private :
    int helper(int arr[], int n, int sum,vector<vector<int>>&dp){
         if(sum==0){
            return 1;
        }
        if(n==0){
            return 0;
        }
        if(dp[n][sum]!=-1){
            return dp[n][sum]%1000000007;
        }
        if(arr[0]<=sum){
            int a=helper(arr+1,n-1,sum-arr[0],dp);
            int b=helper(arr+1,n-1,sum,dp);
            return dp[n][sum]=(a+b)%1000000007;
        }
         return dp[n][sum]=helper(arr+1,n-1,sum,dp)%1000000007;
    }
	public:
	int ans=0;
	int perfectSum(int arr[], int n, int sum)
	{
	    int count=0;
	    for(int i=0;i<n;i++){
	        if(arr[i]==0)
	        {
	             count++;
	        }
	    }
	    vector<vector<int>>dp(n+1, vector<int>(sum+1, -1));
	        sort(arr,arr+n);
	        return pow(2,count)*helper(arr+count,n-count,sum,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends