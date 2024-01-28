//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int lcswithcondition(string s,string t,int n){
        int dp[n+1][n+1];
        for(int i=0;i<n+1;i++){
            for (int j=0;j<n+1;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
                else if(s[i-1]==t[j-1] && i!=j){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
	public:
		int LongestRepeatingSubsequence(string str){
		    return lcswithcondition(str,str,str.size());
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends