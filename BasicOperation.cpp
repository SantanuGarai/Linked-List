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
void makeIntersection(node* &head1,node* &head2,int pos){
    node* temp1 = head1;
    node* temp2 =head2;
    pos--;
    while(pos){
        temp1 = temp1->next;
        pos--;
    }
    while(temp2->next!=NULL){
        temp2 =temp2->next;
    }
    temp2->next = temp1;
    
}
node* mergeIterative(node* &head1,node* &head2){  //Merge 2 Sorted Linked List Iterative way
    node* ptr1 = head1;
    node* ptr2 = head2;
    node* dummynode = new node(-1);
    node* ptr3 = dummynode;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data < ptr2->data){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else{
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }
    while(ptr1){
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }
    while(ptr2){
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }
    return dummynode->next;
}
node* mergeRecursive(node* &head1,node* &head2){ //Merge 2 Sorted Linked List recursive method
   if(head1 == NULL){
       return head2;
   }
   if(head2 == NULL){
       return head1;
   }
   node* result;
   if(head1->data < head2->data){
       result = head1;
       result->next= mergeRecursive(head1->next,head2);
   }
   else{
       result = head2;
       result->next = mergeRecursive(head1,head2->next);
   }
   return result;
}
void evenAfterOdd(node* &head){  //Put Even Position Nodes after Odd Position Nodes
    node* evenstart = head->next;
    node* odd = head;
    node* even = head->next;
    while(odd->next && even->next){
        odd->next = odd->next->next;
        odd = odd->next;
        even->next = even->next->next;
        even = even->next;
    }
    odd->next = evenstart;
    if(even ){
     even->next = NULL;
    }
}
int findIntersect(node* &head1,node* &head2){
    int l1 = length(head1);
    int l2 = length(head2);
    node* ptr1;
    node* ptr2;
    int d;
    if(l1-l2>0){
       d = l1-l2;
       ptr1 = head1;
       ptr2 = head2;
    }
    else if(l1-l2<0){
        d=l2-l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    else{
        ptr1 = head1;
        ptr2 = head2;
    }
    while(d){
        if(ptr1 == NULL){
            return -1;
        }
        ptr1 = ptr1->next;
        d--;
    }
    while(ptr1 && ptr2){
        if(ptr1 == ptr2){
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
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






Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
  
  answer->
  class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;
        int n = 0;
        if(!head || !head->next){
            return head;
        }
        while(temp){
            n++;
            temp = temp->next;
        }
        k = k%n;
        while(fast && k){
            fast = fast->next;
            k--;
        }
        if(!fast){
            return head;
        }
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        fast->next=head;
        head = slow->next;
        slow->next = NULL;
        return head;
    }
};
