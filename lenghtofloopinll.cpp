#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x):data(x),next(NULL){}    
};
int findlength(Node*slow,Node*fast){
    int cnt=1;
    fast=fast->next;
    while(slow!=fast){
        cnt++;
        fast=fast->next;
    }
    return cnt;
}
int LengthOfLoop(Node*head){
    Node*slow=head;
    Node*fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return findlength(slow,fast);
        }
    }
    return 0;
}
int main() {
    // Creating nodes
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Create a loop: last node points to node with value 3
    head->next->next->next->next->next = head->next->next;

    int loopLength = LengthOfLoop(head);
    if (loopLength > 0) {
        cout << "Loop detected with length = " << loopLength << endl;
    } else {
        cout << "No loop detected" << endl;
    }

    return 0;
}
