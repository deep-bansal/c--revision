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

void insertAtHead (node*&head,int d){

  node* newNode = new node(d);
  
  if(head == NULL){  
    newNode->next = newNode;
    head = newNode;
    return;
  }

  newNode->next = head;
  node* temp = head;
  while(temp->next!=head){
    temp = temp->next;
  }
  temp->next = newNode;
  head = newNode;
}
void insertAtTail (node*&head,int d){

  node* newNode = new node(d);
  
  if(head == NULL){  
    newNode->next = newNode;
    head = newNode;
    return;
  }

  node* temp = head;
  while(temp->next!=head){
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->next=head;
}

void printList(node*head){
    node*temp = head;
    while(temp->next!=head){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<temp->data<<" ";
  cout<<endl;

}


int main(int argc, char const *argv[])
{
  node* head= NULL;
  insertAtHead(head,2);
  node*temp = head;
  cout<<temp<<" "<<head<<endl;

  
  return 0;
}
