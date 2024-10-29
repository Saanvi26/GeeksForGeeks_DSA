//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    void dfs(int node,vector<vector<int>>& adj,vector<bool>&visited,stack<int>&stk){
        visited[node]=true;
        for(auto i : adj[node]){
            if(!visited[i]){
                dfs(i,adj,visited,stk);
            }
        }
        stk.push(node);
    }
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        vector<int>ans;
        stack<int>stk;
        vector<bool>visited(adj.size(),false);
        for(int i=0;i<adj.size();i++){
            if(!visited[i]){
                dfs(i,adj,visited,stk);
            }
        }
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends