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


void insertAtTail(node* &head,int data){
    if(head == NULL){
        head = new node(data);
        return;
    }
    node*temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new node(data);
    head = head->next;
    return;
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

node* reveseLL(node*temp){
    if(temp == NULL || temp->next == NULL){
        return temp;
    }
    node* prev = NULL;
    node* curr = temp;
    node* nextNode = temp->next;
    while(nextNode!=NULL){
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        nextNode = nextNode->next;
    }
    curr->next = prev;
    return curr;
}

bool isPal(node* head){
    node* temp1 = head;
    node* temp = reveseLL(temp1);
    cout<<head;
    
    cout<<temp;
    
    while(temp !=NULL && head !=NULL){
        if(temp->data!=head->data) return false;
        temp = temp->next;
        head = head->next;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    node*head = NULL;
    // cin>>head;
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtTail(head,4);
    insertAtTail(head,5);
    printList(head);

    // if(isPal(head))cout<<"true"<<endl;
    // else cout<<"false"<<endl;
    
    
    return 0;
}