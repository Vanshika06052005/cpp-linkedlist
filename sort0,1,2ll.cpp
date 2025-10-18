#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<iterator>
using namespace std;
struct Node{
    int data;
    Node*next;
    Node(int x):data(x),next(NULL){}
};
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
Node*sortll(Node*head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node*zeroh=new Node(-1);
    Node*oneh=new Node(-1);
    Node*twoh=new Node(-1);
    Node*zero=zeroh;
    Node*one=oneh;
    Node*two=twoh;
    Node*temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            zero->next=temp;
            zero=temp;
        }
        else if (temp->data==1){
            one->next=temp;
            one =temp;
        }
        else{two->next=temp;
            two=temp;
        
      }temp=temp->next;
    }
    zero->next=(oneh->next)?(oneh->next):(twoh->next);
    one->next=twoh->next;
    two->next=NULL;
    head=zeroh->next;
    delete zeroh;
    delete oneh;        
    delete twoh;
    return head;
}
int main(){
    int n;
    cout<<"enter size";cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    Node*head=createList(arr);
    printlist(head);
    head=sortll(head);
    printlist(head);
    return 0;
}
