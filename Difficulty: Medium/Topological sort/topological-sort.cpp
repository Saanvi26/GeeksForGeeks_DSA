//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        vector<int>inorder(adj.size(),0);
        
        for(int i=0;i<adj.size();i++){
        for(int j=0;j<adj[i].size();j++){
            inorder[adj[i][j]]++;
        }    
        }
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==0){
                q.push(i); // made an error here 
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
             ans.push_back(node);
            for(auto i :adj[node]){
                inorder[i]--;
                if(inorder[i]==0){
                q.push(i);
            }
            }
        }
         if (ans.size() != adj.size()) {
        return {};  // If not all nodes are included, a cycle exists, so return an empty vector.
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