//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int n=arr.size();
        int i=0;
	    int j=1;
	    while(i<n && j<n){
	        if(arr[i]==0 && arr[j]!=0){
	            swap(arr[i],arr[j]);
	            i++;
	            j++;
	        }
	        else if(arr[i]==0 && arr[j]==0){
	            j++;
	        }
	        else{
	            i++;
	            j++;
	        }
	    }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.pushZerosToEnd(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends