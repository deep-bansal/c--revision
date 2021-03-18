#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode* next;
    ListNode(int d){
        data = d;
        next = NULL;
    }

};


void insertAtTail(ListNode* &head,int data){
    if(head == NULL){
        head = new ListNode(data);
        return;
    }
    ListNode*temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new ListNode(data);
    head = head->next;
    return;
}



int numComponents(ListNode* head, vector<int>& G) {
        ListNode*temp = head;
        int cnt = 0,ans=0;
        while(temp != NULL){
            int x = temp->data;
            auto it = std::find(G.begin(),G.end(),x);
            if( it!=G.end()){
                G.erase(G.begin()+(it-G.begin()));
                cnt++;
            }else{
                ans++;
                cnt = 0;
            }
            temp = temp->next;
        }
        cout<<"cnt val "<<cnt<<endl;        
        if(cnt>0) {
        	ans = ans +1;
        }
        ans+=G.size();
        
        return ans;
        
    }
    void buildLL(ListNode* &head){
    int d;
    cin>>d;
    while(d!=-1){
        insertAtTail(head,d);
        cin>>d;

    }
}

    istream& operator >> (istream& is,ListNode*&head){
    buildLL(head);
    return is;
}

int main(int argc, char const *argv[])
{
	ListNode*head = NULL;
	cin>>head;
	vector<int>G = {0,1,3};
	cout<<numComponents(head,G);
    

    return 0;
}