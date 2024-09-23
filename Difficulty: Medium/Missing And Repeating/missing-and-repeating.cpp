//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int missing;
        int repeating;
        vector<int>ans;
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        for(int i=1;i<=arr.size();i++){
            if(m.find(i)==m.end()){
                missing=i;
            }
            else{
                if(m[i]!=1){
                    repeating=i;
                }
            }
        }
        ans.push_back(repeating);
        ans.push_back(missing);
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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends