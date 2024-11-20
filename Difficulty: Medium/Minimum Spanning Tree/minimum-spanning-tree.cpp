//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	int findParent(int u,vector<int>&parent){
	 if(parent[u]==u) return u;
	 return parent[u]=findParent(parent[u],parent);
	}
	void union_size(int u,int v,vector<int>&size,vector<int>&parent){
	    int pu=findParent(u,parent);
	    int pv=findParent(v,parent);
	    if(pu==pv) return ;
	    if(size[pu]<size[pv]){
	        parent[pu]=pv;
	        size[pv]+=size[pu];
        }
	    else{
	        parent[pv]=pu;
	        size[pu]+=size[pv];
	    }
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
       	vector<int>size(V,1);
       	vector<int>parent(V,0);
       	for(int i=0;i<V;i++){
       	    parent[i]=i;
       	}
       	for (int i = 0; i < V; i++) {
    for (auto &edge : adj[i]) {
        pq.push({edge[1], {i, edge[0]}});
    }
}

       	int s=0;
       	while(!pq.empty()){
       	    int d=pq.top().first;
       	    int u=pq.top().second.first;
       	    int v=pq.top().second.second;
       	    if(findParent(u,parent)!=findParent(v,parent)){
       	        s+=d;
       	        union_size(u,v,size,parent);
       	    }
       	    pq.pop();
       	    
       	}
       	return s;
       	
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends