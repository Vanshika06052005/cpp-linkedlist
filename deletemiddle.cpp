#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node*next;
    Node(int x):data(x),next(NULL){}
};
Node* deleteMiddle(Node* head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        Node*slow=head;
        Node*fast=head;
        fast=head->next->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=slow->next->next;
        return head;
    }
Node*createList(vector<int>arr){
    if(arr.empty())return NULL;
    Node*head=new Node(arr[0]);
    Node*curr=head;
    for(int i=1;i<arr.size();i++){
        curr->next=new Node(arr[i]);
        curr=curr->next;
    }
    return head;
}  
void printlist(Node*head){
    Node*temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<" \n";
}
int main(){
    int  n;
    cout<<"enter size";cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    Node*head=createList(arr);
    printlist(head);
    head=deleteMiddle(head);
    printlist(head);
    return 0;
}