//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        unordered_map<int,list<pair<int,int>>>adj;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<int>parent(n+1,-1);
        vector<int>dist(n+1,INT_MAX);
        dist[1]=0;
        pq.push({0,1});
        while(!pq.empty()){
            int node=pq.top().second;
            int d=pq.top().first;
            for(auto &i : adj[node]){
                int distance=i.second;
                int node2=i.first;
                if(distance+d < dist[node2]){
                    dist[node2]=distance+d ;
                    pq.push({dist[node2],node2});
                    parent[node2]=node;
                }
            }
            pq.pop();
        }
        // int index=n;
          if (dist[n] == INT_MAX) {
        return {-1};
    }
         vector<int> path;
        int index=n;
        while(index!=-1){
            path.push_back(index);
            index=parent[index];
        }

    reverse(path.begin(), path.end());
    path.insert(path.begin(), dist[n]);

    return path;
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends