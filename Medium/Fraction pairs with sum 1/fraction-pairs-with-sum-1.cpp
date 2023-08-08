//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
#include<algorithm>
class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[])
    {
      map< pair<int,int>,int >mpp;
       int ans=0;
       for(int i = 0 ; i < n ;i++){
          int n= numerator[i];
          int d = denominator[i];
          int gcd = __gcd(n,d);
          n=n/gcd;
          d=d/gcd;
          int remaining = d-n;
          //finding  1 - n/d in map 
          if(mpp.find({remaining,d})!=mpp.end())
           {
              //if it is present than add the frequency of it
                ans+=mpp[{remaining,d}];   

         }
           mpp[{n,d}]++;
          
       }
       return ans;

    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends