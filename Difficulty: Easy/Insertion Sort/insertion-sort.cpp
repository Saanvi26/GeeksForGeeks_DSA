//{ Driver Code Starts
// C program for insertion sort
#include <stdio.h>
#include <math.h>

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void insert(int arr[], int i)
    {
        
    }
     public:
     void recur(int arr[],int n,int i){
         if(i>=n){
             return ;
         }
         int temp=arr[i];
         int j;
         for(j =i-1;j>=0;j--){
            if(temp<arr[j]){
                    arr[j+1]=arr[j];
                }
                else{
                    break;
                }
         }
         arr[j+1]=temp;
         i++;
         recur(arr,n,i);
     }
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        recur(arr,n,1);
    }
};

//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;

    scanf("%d",&T);

    while(T--){

    scanf("%d",&n);

    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.insertionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends