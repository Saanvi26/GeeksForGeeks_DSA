//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void dfs(vector<int>&ans,vector<int>adj[],int V,vector<bool>&visited,int node){
       ans.push_back(node);
       visited[node]=true;
       for(auto i : adj[node]){
           if(!visited[i]){
               dfs(ans,adj,V,visited,i);
              visited[i]=true;
           }
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int>adjj[V];
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[0].size();j++){
                if(i==j){
                    continue;
                }
                else if (adj[i][j]==1){
                    adjj[i].push_back(j);
                }
            }
        }
        
        int count=0;
        vector<int>ans;
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                 count++;
                dfs(ans,adjj,V,visited,i);
            }
        }
        return count;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends