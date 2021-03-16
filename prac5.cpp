#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node* prev;
    node* next;
    node(int d){
        data = d;
        next=NULL;
        prev = NULL;
    }
    
};

void insertAtHead(node*&head,int d){
    if(head == NULL){
        head = new node(d);
        return;
    }

    node*temp = new node(d);
    temp->next=head;
    head->prev = temp;
    head = temp;

}

void insertAtTail(node*&head,int d){
    if(head == NULL){
        head = new node(d);
        return;
    }

    node*temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    node* newNode = new node(d);
    temp->next = newNode;
    newNode->prev = temp;
}

int length (node*head){
    int len = 0;
    while(head !=NULL){
        len++;
        head = head->next;
    }
    return len;

}

void insertAtMid(node* &head,int d,int k){
    if(head==NULL || k == 0){
        insertAtHead(head,d);
        return;
    }
    if (k >= length(head) ){
        insertAtTail(head,d);
        return;
    }

    int jump = 1;
    node*temp =head;
    while(jump<=k-1){
        temp = temp->next;
        jump++;
    }

    node*newNode = new node(d);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    newNode->prev = temp;
    temp->next = newNode;

}


void printList(node*head){
    while(head->next != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<head->data<<" ";
    cout<<endl;

    while(head != NULL){
        cout<<head->data<<" ";
        head = head->prev;
    }
    cout<<endl;

}

int main(int argc, char const *argv[])
{
    node*head = NULL;
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,4);
    insertAtTail(head,6);
    insertAtTail(head,7);
    insertAtMid(head,5,4);
    printList(head);

    
    return 0;
}