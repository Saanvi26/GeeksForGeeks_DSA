//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{

public:
    int solver(int arr[],int N,int i,int j ,int t[1001][1001]){
        if(i>=j){
            return t[i][j]=0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        int mn=INT_MAX;
        for(int k=i;k<j;k++){
            int temp=solver(arr,N,i,k,t)+solver(arr,N,k+1,j,t)+arr[i-1]*arr[k]*arr[j];
            if(temp<mn){
                mn=temp;
            }
        }
        return t[i][j]=mn;
        
    }
    int matrixMultiplication(int N, int arr[])
    {
        int i=1;
        int j=N-1;
         int  t[1001][1001];
         for(int s=0;s<1001;s++){
             for(int p=0;p<1001;p++){
                 t[s][p]=-1;
             }
         }
        return solver(arr,N,i,j,t);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends