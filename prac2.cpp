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

// node* mergeTwoLLRec(node*&a,node*&b){
//     if(a == NULL) return b;
//     if(b == NULL) return a;

//     node*c;
//     if(a->data <= b->data){
//         c = a;
//         c->next = mergeTwoLLRec(a->next,b);
//     }else{
//         c = b;
//         c->next = mergeTwoLLRec(a,b->next);
//     }
//     return c;
// }

node* mergeTwoLL(node*a,node*b){
    node*ans = new node(0);
    node* c = ans;
    while(a!=NULL && b!=NULL){
        if(a->data<=b->data){
            c->next = a;
            a = a->next;
        }
        else{
            c->next = b;
            b = b->next;
        }
        c = c->next;
    }

    if(a == NULL && b!=NULL) c ->next = b;
    else if(a != NULL && b==NULL) c ->next = a;
    return ans->next;
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

void mergeSort(node* &head){
    if(head == NULL || head->next == NULL){
        return;
    }
    node* midNode = mid(head);
    node*a = head;
    node* b = midNode->next;
    midNode->next=NULL;
    mergeSort(a);
    mergeSort(b);
    head = mergeTwoLL(a,b);

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
    // node*a = NULL;
    node*b = NULL;
    cin>>b;
    // cout<<a<<b;
    // reveseLL(head);
    // cout<<head;
    // reverseLLRec(head);
    // cout<<temp;
    // node* ans =kthNodeFromLast(head,3);
    // if(ans != NULL){
    //     cout<<ans->data<<endl;
    // }

    // node* ans = mergeTwoLLRec(a,b);
    // // ans = ans->next;
    // cout<<ans;
    mergeSort(b);
    cout<<b;

    
    return 0;
}