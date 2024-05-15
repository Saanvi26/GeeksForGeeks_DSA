//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n){
         int start=0;
        int end=n-1;
       int ans=-1;
       while(start<end){
            int mid=(start+end)/2;
            
            if(arr[mid]< arr[mid+1] && arr[mid]< arr[mid-1]){
                return arr[mid];
            }
            else if (arr[mid]>arr[mid-1]&& arr[mid]<arr[mid+1]){
                if(arr[start]<arr[mid-1] && arr[end]>arr[mid+1]){
                    return arr[start];
                }
                else if(arr[mid-1] > arr[start])
                start=mid+1;
                else {
                    end=mid;
                }
            }
            else if (arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                return arr[mid+1];
            }
       }
      
       return ans;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends