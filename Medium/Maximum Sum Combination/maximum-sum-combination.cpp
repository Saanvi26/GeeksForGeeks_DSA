//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        sort(A.rbegin(),A.rend());
         sort(B.rbegin(),B.rend());
        priority_queue< pair<int,pair<int,int>> >pq;
        pq.push({A[0]+B[0],{0,0}});
        vector<int>ans;
        set<pair<int,int>>s;
        s.insert({0,0});
        for(int t=0;t<K;t++){
            int sum=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
             pq.pop();
            ans.push_back(sum);
            if(i+1 < N && j<N &&  s.find({i+1,j})==s.end()){
                pq.push({A[i+1]+B[j],{i+1,j}});
                s.insert({i+1,j});
            }
            if(j+1 < N && i<N && s.find({i,j+1})==s.end()){
                pq.push({A[i]+B[j+1],{i,j+1}});
                s.insert({i,j+1});
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends