//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

 class Solution {
public:
    long long int atmostKDistinct(string s, int k) {
        vector<int> count(26, 0);  // Count of characters in the current window
        int distinctCount = 0;     // Number of distinct characters in the current window
        int i = 0;
        long long int ans = 0;

        for (int j = 0; j < s.size(); ++j) {
            // Add the current character to the window
            if (count[s[j] - 'a'] == 0) {
                distinctCount++;  // Increase distinct count if it's a new character
            }
            count[s[j] - 'a']++;

            // Shrink the window if there are more than k distinct characters
            while (distinctCount > k) {
                count[s[i] - 'a']--;
                if (count[s[i] - 'a'] == 0) {
                    distinctCount--;  // Decrease distinct count if a character count drops to 0
                }
                i++;
            }

            // Count valid substrings ending at j
            ans += (j - i + 1);
        }

        return ans;
    }

    long long int substrCount(string s, int k) {
        return atmostKDistinct(s, k) - atmostKDistinct(s, k - 1);
    }
};


//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends