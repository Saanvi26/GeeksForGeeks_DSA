//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool dfs(int node,int parent,vector<vector<int>>&adj,vector<bool>&visited){
        visited[node]=true;
        for(auto i :adj[node]){
            if(!visited[i]){
                if(dfs(i,node,adj,visited)){
                    return true;
                }
            }
            else if (i!=parent){
                return true;
            }
        }
        return false;
    }
    bool isCycle(vector<vector<int>> adj) {
        vector<bool>visited(adj.size(),false);
        for(int i=0;i<adj.size();i++){
            if(!visited[i]){
                if(dfs(i,-1,adj,visited))
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends