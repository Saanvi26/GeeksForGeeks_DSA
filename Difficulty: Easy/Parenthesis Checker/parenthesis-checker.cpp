//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
       stack<char>stk;
       for(auto i : x){
           if(i=='(' || i=='[' || i=='{'){
               stk.push(i);
           }
           else if(i==')' && !stk.empty() && stk.top()=='('){
               stk.pop();
           }
           else if (i==']' && !stk.empty() && stk.top()=='['){
               stk.pop();
           }
           else if (i=='}' && !stk.empty() && stk.top()=='{'){
               stk.pop();
           }
           else{
               return false;
           }
       }
       return stk.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends