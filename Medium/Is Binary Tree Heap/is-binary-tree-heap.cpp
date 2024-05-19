//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
    bool CBT(struct Node* root,vector<int>&arr,int i){
        if(root==NULL){
            return true;
        }
        if(i>=arr.size()){
            return false;
        }
        
         if (root->data != arr[i]) {
        return false;
        }
        // if(root->left){
        //     if(root->left->data !=arr[2*i+1]){
        //         return false;
        //     }
        // }
        // if(root->right){
        //     if(root->right->data !=arr[2*i+2]){
        //         return false;
        //     }
        // }
        return CBT(root->left, arr, 2 * i + 1) && CBT(root->right, arr, 2 * i + 2);
    
    }
    bool check(struct Node* root){
        if(root==NULL){
            return true;
        }
        bool l=true;
        bool r=true;
        if(root->left){
            if(root->left->data > root->data){
                l=false;
            }
        }
        if(root->right){
            if(root->right->data > root->data){
                r=false;
            }
        }
        
      return (l&&r)&&check(root->left) & check(root->right);
    }
    vector<int> getVectorOfTree(struct Node* root, vector<int>&arr){
        queue< Node*>q;
        q.push(root);
        while(!q.empty()){
            int count=q.size();
            while(count--)
            {
                arr.push_back(q.front()->data);
            
                if(q.front()->left){
                q.push(q.front()->left);
            }
              if(q.front()->right){
                  q.push(q.front()->right);
            }
                q.pop();
            }
        }
        return arr;
    }
  public:
    bool isHeap(struct Node* tree) {
        vector<int>arr;
        getVectorOfTree(tree,arr);
        bool result=CBT(tree,arr,0);
        return check(tree) && result;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
// } Driver Code Ends