//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int>distance(100000,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,start});
        distance[start]=0;
        while(!pq.empty()){
            int num=pq.top().second;
            int steps=pq.top().first;
            if(num==end){
                return steps;
            }
            pq.pop();
            for(auto k:arr){
                if(distance[(k*num)%100000] > distance[num]+steps){
                    distance[(k*num)%100000]=distance[num]+steps;
                pq.push({steps+1,(k*num)%100000});
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends