//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        priority_queue <long long, vector<long long>, greater<long long> > pq;
        long long ans=0;
         long long sum=0;
        for(auto i : arr){
            pq.push(i);
        }
        while (pq.size() > 1) {
        // Pop the two smallest elements
        long long first = pq.top(); pq.pop();
        long long second = pq.top(); pq.pop();

        // Add their sum to the total cost
        long long ans = first + second;
        sum += ans;

        // Push the combined element back into the priority queue
        pq.push(ans);
    }
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends