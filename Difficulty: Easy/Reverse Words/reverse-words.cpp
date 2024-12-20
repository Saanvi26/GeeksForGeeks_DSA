//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        stack<string>stk;
        string temp="";
        for(int i=0;i<str.length();i++){
            if(str[i]=='.'){
                stk.push(temp);
                temp="";
                continue;
            }
            temp+=str[i];
        }
        stk.push(temp);
        string ans="";
        while(!stk.empty()){
            ans+=stk.top();
            ans+=".";
            stk.pop();
        }
        ans.pop_back();
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends