#include <iostream>
using namespace std;

class node{
  public:
    int data;
    node* next;
    
    node(int val){
        data=val;
        next=NULL;
    }
};
void insertAtTail(node* &head,int val){
    node* n = new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL){
       temp = temp->next;
    }
    temp->next=n;
}
void insertAtHead(node* &head,int val){
    node* n = new node(val);
    n->next=head;
    head=n;
}
void insertAtMiddle(node* &head,int element,int val){  // insert elemnent after a particular node
    node* n = new node(val);
    node* temp=head;
    while(temp->data!=element){
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next=n;
}
void insertAtMiddle2(node* &head,int element,int val){  //insert a node before a particular node
    node* n = new node(val);
    if(head->data == element){
       n->next=head;
       head=n;
       return;
    }
    node* temp = head;
    while(temp->next->data != element){
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
}
void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
    
}
int main() {
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    display(head);
    insertAtHead(head,4);
    display(head);
    insertAtMiddle(head,2,30);
    display(head);
    insertAtMiddle2(head,30,80);
    display(head);
    insertAtMiddle2(head,4,90);
    display(head);
	return 0;
}
