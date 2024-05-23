//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    int K=pat.size();
	    int count=0;
	    if(K>txt.size()){
	        return 0;
	    }
	    vector<int>txt_v(26,0);
	    vector<int>pat_v(26,0);
	    for(int i=0;i<K;i++){
	        pat_v[pat[i]-'a']++;
	        txt_v[txt[i]-'a']++;
	    }
	    bool check=true;
	    for(int i=0;i<26;i++){
	        if(pat_v[i]!=txt_v[i]){
	            check=false;
	            break;
	        }
	    }
	    if(check){
	        count++;
	    }
	    int j=K;
	    int i=0;
	    while(j<txt.size()){
	        txt_v[txt[i]-'a']--;
	        txt_v[txt[j]-'a']++;
	        bool chk=true;
	        for(int i=0;i<26;i++){
	        if(pat_v[i]!=txt_v[i]){
	            chk=false;
	        }
	       }
	    if(chk){
	        count++;
	    }
	    j++;
	    i++;
	   }
	   return count;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends