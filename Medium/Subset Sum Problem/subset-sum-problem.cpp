//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

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
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
          vector<vector<int>>dp(arr.size()+1, vector<int>(sum+1, -1));
          int a[arr.size()];
          for (int i=0;i<arr.size();i++){
              a[i]=arr[i];
          }
          if(helper(a,arr.size(),sum,dp)){
              return true;
          }
          return false;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends