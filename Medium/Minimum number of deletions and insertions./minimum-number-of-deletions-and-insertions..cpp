//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private :
    int lcs(string s,string t){
        int n=s.size();
        int m=t.size();
        int dp[n+1][m+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
                else if (s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
	public:
	int minOperations(string str1, string str2) 
	{ 
	 return str1.size()-lcs(str1,str2)+str2.size()-lcs(str1,str2);
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends