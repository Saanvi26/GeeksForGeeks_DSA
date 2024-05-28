//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
   void fact(vector<long long>&ans,long long N,long long i,long long f){
       if(f>N){
           return ;
       }
       ans.push_back(f);
       f=f*i;
       fact(ans,N,i+1,f);
   }
    vector<long long> factorialNumbers(long long N)
    {
        vector<long long>ans;
        fact(ans,N,2,1);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin>>N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for(auto num : ans){
            cout<<num<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}
// } Driver Code Ends