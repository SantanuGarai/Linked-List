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
node* reverse_iterative(node* &head){
    node* previous = NULL;
    node* current = head;
    node* Next;
    while(current != NULL){
        Next = current->next;
        current->next = previous;
        previous = current;
        current = Next;
    }
    return previous;
}
node* reverse_recursion(node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node* newhead = reverse_recursion(head->next);
    head->next->next = head;
    head -> next = NULL;
    return newhead;
}
void makecycle(node* &head, int val){
    node* temp = head;
    node* ptr;
    int count = 1;
    while(temp->next!= NULL){
        if(val == count){
            ptr = temp;
        }
        count++;
        temp = temp->next;
    }
    temp->next = ptr;
}
bool detectCycle(node* &head){
    node* slow=head;
    node* fast=head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
}
void removeCycle(node* &head){
    node* slow = head;
    node* fast = head;
    do{
      fast=fast->next->next;
      slow = slow->next;
    }while(fast != slow);
    fast = head;
    while(fast->next != slow->next){
      fast = fast->next;
      slow = slow->next;
   }
   slow->next=NULL;
}
int length(node* head){
    node* temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
node* kappend(node* &head,int k){  //Append Last K Nodes of a Linked List
    node* newhead;
    node* newtail;
    node* tail = head;
    int l = length(head);
    int count = 1;
    while(tail->next!=NULL){
        if(count == (l-k+1)){
            newhead = tail;
        }
        if(count == (l-k)){
            newtail = tail;
        }
        count++;
        tail = tail->next;
    }
    tail->next = head;
    newtail->next = NULL;
    return newhead;
}
void deleteAtTail(node* &head){
    node* temp=head;
    head = head ->next;
    delete temp;
}
void deletion(node* &head,int val){
    if(head==NULL){
        cout<<"underflow";
        return;
    }
    node* todelete;
    if(head->next==NULL){
        todelete = head;
        head = NULL;
        delete todelete;
        return;
    }
    node* temp = head;
    while(temp->next->data != val){
        temp = temp->next;
    }
    todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
    
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
    makecycle(head,3);
    cout<<detectCycle(head)<<endl;
    removeCycle(head);
    cout<<detectCycle(head)<<endl;
    display(head);
    insertAtHead(head,4);
    display(head);
    insertAtMiddle(head,2,30);
    display(head);
    insertAtMiddle2(head,30,80);
    display(head);
    insertAtMiddle2(head,4,90);
    display(head);
    insertAtTail(head,3);
    deletion(head,3);
    display(head);
    deleteAtTail(head);
    display(head);
    node* newhead;
    newhead = reverse_iterative(head);
    display(newhead);
    newhead = reverse_recursion(newhead);
    display(newhead);
    return 0;
}
