//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private :
  void solve(vector<vector<int>> &m, vector<vector<int>> &visited, vector<string> &ans, int n, string s, int x, int y) {
    if (x == n - 1 && y == n - 1) {
        ans.push_back(s);
        return;
    }
    visited[x][y]=1;
    if (x + 1 < n && m[x + 1][y] == 1 && visited[x + 1][y] == 0) {
        s += 'D';
        visited[x + 1][y]=1;
        solve(m, visited, ans, n, s, x + 1, y);
        s.pop_back(); // Backtrack
         visited[x + 1][y]=0;
    }
    if (y + 1 < n && m[x][y + 1] == 1 && visited[x][y + 1] == 0) {
        s += 'R';
        visited[x][y + 1]=1;
        solve(m, visited, ans, n, s, x, y + 1);
        s.pop_back(); // Backtrack
         visited[x][y + 1]=0;
    }
    if (x - 1 >= 0 && m[x - 1][y] == 1 && visited[x - 1][y] == 0) {
        s += 'U';
        visited[x - 1][y]=1;
        solve(m, visited, ans, n, s, x - 1, y);
        s.pop_back(); // Backtrack
         visited[x - 1][y]=0;
    }
    if (y - 1 >= 0 && m[x][y - 1] == 1 && visited[x][y - 1] == 0) {
        s += 'L';
        visited[x][y - 1]=1;
        solve(m, visited, ans, n, s, x, y - 1);
        s.pop_back(); // Backtrack
         visited[x][y - 1]=0;
    }
   
}
    public:
   vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> ans;
    string s;
    if (m[0][0] == 0) {
        return ans;
    }
    vector<vector<int>> visited(n, vector<int>(n, 0));
    solve(m, visited, ans, n, s, 0, 0);
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
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends