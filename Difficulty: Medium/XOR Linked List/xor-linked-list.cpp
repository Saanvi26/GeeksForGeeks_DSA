//{ Driver Code Starts
#include <stdint.h>

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *npx;

    Node(int x) {
        data = x;
        npx = NULL;
    }
};

struct Node *XOR(struct Node *a, struct Node *b) {
    return (struct Node *)((uintptr_t)(a) ^ (uintptr_t)(b));
}

struct Node *insert(struct Node *head, int data);

vector<int> getList(struct Node *head);

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        struct Node *head = NULL;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            head = insert(head, number);
        }

        vector<int> vec = getList(head);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
        for (int i = vec.size() - 1; i >= 0; i--) {
            cout << vec[i] << " ";
        }
        cout << "\n";
    }
    return (0);
}

// } Driver Code Ends


/*
Structure of linked list is as
struct Node
{
    int data;
    struct Node* npx;

    Node(int x){
        data = x;
        npx = NULL;
    }
};

Utility function to get XOR of two Struct Node pointer
use this function to get XOR of two pointers
struct Node* XOR (struct Node *a, struct Node *b)
{
    return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}
*/

// function should insert the data to the front of the list
// function should insert the data to the front of the list
struct Node *insert(struct Node *head, int data) {
    // create the new node and set the pointer to the head
    Node* newNode = new Node(data);
    newNode->npx = head;
    // head pointer is the previous node, XOR it to new node
    if(head)
    {
        head->npx = XOR(head->npx, newNode);
    }
    return newNode;
}

vector<int> getList(struct Node *head) {
    // vector containing the answer
    vector<int> theList;
    // run through the list
    while(head)
    {
        // insert the data to vector
        theList.push_back(head->data);
        // head points just to the next node
        Node* next = head->npx;
        // using the XOR again will cancel the head address
        if(next)
        {
            next->npx = XOR(next->npx, head);
        }
        // increase the list
        head = next;
    }
    return theList;
}
