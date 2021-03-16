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

istream& operator >> (istream& is,node*&head){
    buildLL(head);
    return is;
}

ostream& operator << (ostream& os,node*&head){
    printList(head);
    return os;
}

void reveseLL(node*&head){
    if(head == NULL || head->next == NULL){
        return;
    }
    node* prev = NULL;
    node* curr = head;
    node* nextNode = head->next;
    while(nextNode!=NULL){
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        nextNode = nextNode->next;
    }
    curr->next = prev;
    head = curr;
}

node*temp;
void reverseLLRec(node* head){
    if(head == NULL || head->next == NULL) { temp = head; return;}

    reverseLLRec(head->next);

    head->next->next = head;
    head->next =NULL;

    return;
}

node* kthNodeFromLast(node*head,int k){

    node*fast=head;
    node*slow= head;

    while(k>1){
        if(fast == NULL){
            cout<<"K is greater than length of LL"<<endl;
            return NULL;
        }
        fast = fast->next;
        k--;
    }
    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}


int main(int argc, char const *argv[])
{
    node*head = NULL;
    cin>>head;
    cout<<head;
    // reveseLL(head);
    // cout<<head;
    reverseLLRec(head);
    cout<<temp;
    // node* ans =kthNodeFromLast(head,3);
    // if(ans != NULL){
    //     cout<<ans->data<<endl;
    // }
    
    return 0;
}