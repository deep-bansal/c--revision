#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* right;
    node* down;
    node(int d){
        data = d;
        right = NULL;
        down = NULL;
    }

};

// void insertAtHead(node* &head, int data) {
//     if (head == NULL) {
//         head = new node(data);
//         return;
//     }

//     node* temp = new node(data);
//     temp->next = head;
//     head = temp;
//     return;
// }

void insertAtDown(node* &head,int data)
{
    if(head==NULL)
    {
        head=new node(data);
        return;
    }
    node*temp=head;
    while(temp->down!=NULL)
    {
        temp=temp->down;

    }
    temp->down=new node(data);
    return;
}


// int length(node*head){
//     int len = 0;
//     while(head != NULL){
//         len++;
//         head = head->next;
//     }
//     return len;
// }


void printList(node* head){
    if(head == NULL){
        cout<<"List is Empty"<<endl;
        return;
    }

    while(head != NULL){
        cout<<head->data<<" ";
        head= head->down;
    }
    cout<<endl;
}

// void buildLL(node* &head){
//     int d;
//     cin>>d;
//     while(d!=-1){
//         insertAtTail(head,d);
//         cin>>d;

//     }
// }

node* mergeTwoLLRec(node*a,node*b){
    if(a == NULL) return b;
    if(b == NULL) return a;

    node*c;
    if(a->data <= b->data){
        c = a;
        c->down = mergeTwoLLRec(a->down,b);
    }else{
        c = b;
        c->down = mergeTwoLLRec(a,b->down);
    }
    return c;
}

node* flatLL(node*head)
{
    if(head==NULL || head->right==NULL)
    {
        return head;
    }
    node*c=mergeTwoLLRec(head,flatLL(head->right));
    return c;
}

// istream& operator >> (istream& is,node*&head){
//     buildLL(head);
//     return is;
// }

ostream& operator << (ostream& os,node*&head){
    printList(head);
    return os;
}

int main(int argc, char const *argv[])
{
    // node*a = NULL;
    node* head = NULL;
    insertAtDown(head, 3);
    insertAtDown(head, 9);
    insertAtDown(head, 10);
    insertAtDown(head, 15);
    insertAtDown(head->right, 4);
    insertAtDown(head->right, 14);
    insertAtDown(head->right, 20);
    insertAtDown(head->right, 25);
    insertAtDown(head->right, 35);
    insertAtDown(head->right->right, 1);
    insertAtDown(head->right->right, 10);
    insertAtDown(head->right->right, 12);
    head= flatLL(head);
    printList(head);

    
    return 0;
}