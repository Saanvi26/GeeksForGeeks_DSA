//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void constructLps(string &pat, vector<int> &lps) {

    // len stores the length of longest prefix which
    // is also a suffix for the previous index
    int len = 0;

    // lps[0] is always 0
    lps[0] = 0;

    int i = 1;
    while (i < pat.length()) {

        // If characters match, increment the size of lps
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }

        // If there is a mismatch
        else {
            if (len != 0) {

                // Update len to the previous lps value
                // to avoid reduntant comparisons
                len = lps[len - 1];
            }
            else {

                // If no matching prefix found, set lps[i] to 0
                lps[i] = 0;
                i++;
            }
        }
    }
}

bool search(string &pat, string &txt,vector<int>lps) {
    int n = txt.length();
    int m = pat.length();
    int i = 0;
    int j = 0;
    while (i < n) {
        if (txt[i] == pat[j]) {
            i++;
            j++;
            if (j == m) {
                return true;
                j = lps[j - 1];
            }
        }

        else {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return false;
}

    int minRepeats(string& s1, string& s2) {
        string s="";
        int steps=0;
        vector<int>lps(s2.size());
        constructLps(s2, lps);
      int limit = (s2.size() / s1.size()) + 2;
        while(steps<=limit && !search(s2,s,lps)){
            s=s+s1;
            steps++;
        }
        if(steps>limit) return -1;
        return steps;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}
// } Driver Code Ends