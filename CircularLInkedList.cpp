#include <iostream>
using namespace std;
class node{
    public:
       int data;
       node* next;
       
     node(int val){
         data = val;
         next = NULL;
     }
};
void insertAtHead(node* &head,int val){
    node* n = new node(val);
    if(head == NULL){
        n->next = n;
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}
void insertAtTail(node* &head, int val){
    if(head == NULL){
        insertAtHead(head,val);
        return;
    }
    node* n = new node(val);
    node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}
void deleteAtHead(node* &head){
    if(head ==NULL){
        return;
    }
    if(head->next == head){
        delete head;
        head == NULL;
        return;
    }
    node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    node* todelete = head;
    temp->next = head->next;
    head = head->next;
    delete todelete;

}
void deletion(node* &head,int pos){
    if(head == NULL){
        return;
    }
    if(pos == 1){
        deleteAtHead(head);
        return;
    }
    node* temp = head;
    int count = 1;
    while(pos-1 == count){
        count ++;
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
    
}
void display(node* head){
    if(head == NULL){
        cout<<"Linked list is empty"<<endl;
        return;
    }
    node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
        
    }while(temp!=head);
    cout<<endl;
}
int main() {
    
	node* head = NULL;
	int arr[] = {1,2};
	for(int i=0;i<2;i++){
	    insertAtTail(head,arr[i]);
	}
	display(head);
	insertAtHead(head,6);
	display(head);
	deletion(head,3);
	display(head);
	deleteAtHead(head);
	display(head);
	return 0;
}
