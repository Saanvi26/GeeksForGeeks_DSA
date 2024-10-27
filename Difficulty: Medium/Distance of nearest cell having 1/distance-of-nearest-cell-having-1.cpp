//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    q.push({{i,j},0});
                    visited[i][j]=true;
                }
            }
        }
         vector<vector<int>> ans(row, vector<int>(col, 0));
        while(!q.empty()){
            int dist=q.front().second;
            int ii=q.front().first.first;
            int jj=q.front().first.second;
            q.pop();
            ans[ii][jj]=dist;
            if(ii+1<row && !visited[ii+1][jj] && grid[ii+1][jj]==0){
                q.push({{ii+1,jj},dist+1});
                visited[ii+1][jj]=true;
            }
            if(jj+1<col && !visited[ii][jj+1] && grid[ii][jj+1]==0){
                q.push({{ii,jj+1},dist+1});
                visited[ii][jj+1]=true;
            }
            if(ii-1>=0 && !visited[ii-1][jj] && grid[ii-1][jj]==0){
                q.push({{ii-1,jj},dist+1});
                visited[ii-1][jj]=true;
            }
            if(jj-1>=0 && !visited[ii][jj-1] && grid[ii][jj-1]==0){
                q.push({{ii,jj-1},dist+1});
                visited[ii][jj-1]=true;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends