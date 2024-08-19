//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool check(vector<int>arr,int sum,int index,vector<vector<int>> &dp){
           if(sum==0) return dp[index][sum]=true;
        if(index>=arr.size() && sum!=0) return dp[index][sum]=false;
        if(dp[index][sum]!=-1) return dp[index][sum];
        
        if(arr[index]<=sum){
            return dp[index][sum]=(check(arr,sum-arr[index],index+1,dp)) | (check(arr,sum,index+1,dp));
        }
        return dp[index][sum]=check(arr,sum,index+1,dp);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        vector<vector<int>> dp(arr.size() + 1, vector<int>(sum + 1, -1));
        return check(arr,sum,0,dp);
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