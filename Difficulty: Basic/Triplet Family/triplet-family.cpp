//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        int i=0;
        int j=0;
        sort(arr.begin(),arr.end());
        while(j<arr.size()){
            int s=arr[i];
            j++;
            int left=1;
            int right=arr.size()-1;
            while(left<right){
                if(arr[left]+arr[right]==s){
                    return true;
                }
                else if (arr[left]+arr[right]>s){
                    right--;
                }
                else{
                    left++;
                }
            }
            swap(arr[i],arr[j]);
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends