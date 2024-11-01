//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   public:
    void dfs(char ch, unordered_map<char, list<char>> &m, vector<bool> &visited, string &ans) {
        visited[ch - 'a'] = true;
        for (auto i : m[ch]) {
            if (!visited[i - 'a']) {
                dfs(i, m, visited, ans);
            }
        }
        ans = ch + ans; // Append at the beginning to simulate stack
    }

    string findOrder(string dict[], int n, int k) {
        unordered_map<char, list<char>> m;

        // Build graph
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < min(dict[i].size(), dict[i + 1].size()); j++) {
                if (dict[i][j] != dict[i + 1][j]) {
                    m[dict[i][j]].push_back(dict[i + 1][j]);
                    break;
                }
            }
        }

        // Topological Sort
        string ans = "";
        vector<bool> visited(26, false); // Large enough for 'a'-'z'

        for (char i = 'a'; i < 'a' + k; i++) {
            if (!visited[i - 'a'] && m.find(i) != m.end()) {
                dfs(i, m, visited, ans);
            }
        }

        return ans;
    }

};

//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends