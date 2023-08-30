//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    private:
     void reverse(Node** head)
{
    if (!head)
        return;
    reverseUtil(*head, NULL, head);
}
void reverseUtil(Node* curr, Node* prev, Node** head)
{
    if (!curr->next) {
        *head = curr;
        curr->next = prev;
        return;
    }
    Node* next = curr->next;
    curr->next = prev;
    reverseUtil(next, curr, head);
}
    public:
    Node *compute(Node *head)
    {
        if(head==NULL){
            return head;
        }
         reverse(&head);
         Node * temp=head;
            Node * temp2=head;
             Node * temp3=temp2;
         int max = temp->data;
Node* newHead = temp;
Node* newTail = temp;
temp = temp->next;

while (temp != nullptr) {
    if (temp->data >= max) {
        max = temp->data;
        newTail->next = temp;
        newTail = temp;
    }
    temp = temp->next;
}

newTail->next = nullptr;
         reverse(&temp2);
        return temp2;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends