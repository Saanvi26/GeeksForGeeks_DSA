//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int n=mat.size();
        vector<int>temp;
        int sum=0;
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               sum+=mat[i][j];
           }
        //   cout<<sum<<endl;
           if(sum==0){
               temp.push_back(i);
           }
            sum=0;
       }
       int ans=-1;
       for(auto i : temp){
        //   cout<<i<<" ";
           bool check=true;
           for(int j=0;j<n;j++){
                //  cout<<mat[j][i]<<" ";
               if(i==j){
                   continue;
               }
               if(mat[j][i]==0){
                   check=false;
               }
           }
           if(check==true){
               ans=i;
               return ans;
           }
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends