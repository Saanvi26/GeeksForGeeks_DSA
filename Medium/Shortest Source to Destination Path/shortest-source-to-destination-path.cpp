//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     int shortestDistance(int n, int m, vector<vector<int>> grid, int X, int Y) {
        // code here
        queue<pair<int,pair<int, int>>> q;
        vector<vector<int>>visited(n, vector<int>(m,0));
        q.push({0,{0,0}});
        
        
        int a1[] ={-1,0,1,0};
        int a2[] ={0,1,0,-1};
        
        while(!q.empty())
        {
            int steps = q.front().first;
            int x = q.front().second.first;
            int y =q.front().second.second;
            q.pop();
            
            
            int ans = INT_MAX;
            ans = min (ans,steps);
            if(x == X &&y ==Y)
            return ans;
            
            for( int i = 0; i< 4; i++)
            {
                int newx = x+a1[i];
                int newy = y+a2[i];
                
                if(newx<n && newy <m && newx>=0&&newy>=0 && !visited[newx][newy] && grid[newx][newy]==1)
                {
                    q.push({steps+1,{newx,newy}});
                    visited[newx][newy]=1;
                }
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends