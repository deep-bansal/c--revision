#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* next;
    node(int d){
        data = d;
        next = NULL;
    }

};

int length(node*head){
    int len = 0;
    while(head != NULL){
        len++;
        head = head->next;
    }
    return len;
}
void insertAtTail(node*&head,int data){
    if(head == NULL){
        head = new node(data);
        return;
    }
    node*temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new node(data);
    return;
}

node* detectCycle(node* head){
    node* slow = head;
    node* fast = head;
    while(fast!=NULL and fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow){
            return slow;
        }
    }
    return NULL;
}


void printList(node* head){
    if(head == NULL){
        cout<<"List is Empty"<<endl;
        return;
    }

    while(head != NULL){
        cout<<head->data<<" ";
        head= head->next;
    }
    cout<<endl;
}

void buildLL(node* &head){
    int d;
    cin>>d;
    while(d!=-1){
        insertAtTail(head,d);
        cin>>d;

    }
}

void removeCycle(node*head,node* meetPoint){
    node* A = head;
    node*prev = NULL;
    while(A!=meetPoint){
        A = A->next;
        prev= meetPoint;
        meetPoint = meetPoint->next;
    }
    prev->next = NULL;
}


istream& operator >> (istream& is,node*&head){
    buildLL(head);
    return is;
}

ostream& operator << (ostream& os,node*&head){
    printList(head);
    return os;
}


int main(int argc, char const *argv[])
{
    node*head = NULL;
    // cin>>head;

    // cout<<head;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,7);
    head->next->next->next->next->next->next->next = head->next->next;
    cout<<head;

    removeCycle(head,detectCycle(head));
    cout<<head;
    
    return 0;
}