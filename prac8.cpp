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

void insertAtHead(node* &head, int data) {
    if (head == NULL) {
        head = new node(data);
        return;
    }

    node* temp = new node(data);
    temp->next = head;
    head = temp;
    return;
}

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


void insertAtMid(node*&head,int data,int p){
    if(p == 0){
        insertAtHead(head,data);
        return;
    } else if(p>length(head)){
       insertAtTail(head,data);
        return;
    }
    else{
        node*temp = head;
        int jump = 1;        
        while(jump<=p-1){
            temp = temp->next;
            jump++;
        }

        node* newNode = new node(data);
        newNode->next = temp->next;
        temp->next = newNode;

    }
}

void deleteAtHead(node* &head){
    if(head == NULL)return;

    node*temp = head;
    head = head->next;
    delete temp;
}

void deleteAtTail(node*&head){
    if(head == NULL || head->next == NULL) {
        deleteAtHead(head);
         return;
     }

    node*temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void deleteAtMid(node*&head,int k){
    if(k == 1 || head == NULL || head->next == NULL){
        deleteAtHead(head);
        return;
    }
    else if(k>=length(head)){
        deleteAtTail(head);
        return;
    }
    else{
        node*temp = head;
        int jump = 1;
        while(jump<k-1){
            temp = temp->next;
            jump++;
        }

        node* toDel = temp->next;
        temp->next = temp->next->next;
        delete toDel;
    }
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

istream& operator >> (istream& is,node*&head){
    buildLL(head);
    return is;
}

ostream& operator << (ostream& os,node*&head){
    printList(head);
    return os;
}

bool searchIterative(node*head,int data){

    while(head != NULL){
        if(head->data == data){
            return true;
        }
        head = head->next;
    }
    return false;

}

bool searchRecursive(node*head,int d){
    if(head == NULL){
        return false;
    }
    if(head -> data == d){
        return true;
    }
    return searchRecursive(head->next,d);
}

node* mid(node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    node*slow=head;
    node*fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}


int main(int argc, char const *argv[])
{
    node*head = NULL;
    cin>>head;
    cout<<head;
    // cout<<mid(head)->data<<endl;
    return 0;
}