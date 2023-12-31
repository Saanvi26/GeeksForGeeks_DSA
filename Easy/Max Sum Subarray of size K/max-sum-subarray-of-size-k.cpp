//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        long long int sum=0;
        for(int i=0;i<K;i++){
            sum+=Arr[i];
        }
          long long int ans=0;
          ans=sum;
        long long int sum2=sum;
        for (int i=1;i<=N-K;i++){
            sum2=sum2-Arr[i-1];
            sum2+=Arr[K+i-1];
            if(sum2 >ans){
                ans=sum2;
            }
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
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends