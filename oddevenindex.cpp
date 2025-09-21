#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int x):data(x),next(NULL){}    
};
Node*oddeven(Node*head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node*odd = head;
    Node*even = head->next;
    Node*evenhead=even;
    while(even!=NULL && even->next!=NULL){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=evenhead;
    return head;
}
    Node*createlist(vector<int>arr,int n) {
        Node*head=new Node(arr[0]);
        Node*curr=head;
        for(int i=0;i<n;i++){
            curr->next=new Node(arr[i]);
            curr=curr->next;
        }
        return head;
    }
    Node*printlist(Node*head){
        Node*curr=head;
        while(curr!=NULL){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        cout<<"\n";
    }
    int main(){
        int n;
        cout<<"enter teh size";
        cin>>n;
        vector<int>arr(n);
        cout<<"enter  the elements";
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Node*head=createlist(arr,n);
        printlist(head);
        head=oddeven(head);
        printlist(head);
        return 0;

    }
