void reverseLL(Node* &list){
        Node* curr = list;
        Node*prev=NULL;
        Node*nextN = list->next;
        while(nextN !=NULL){
            curr->next = prev;
            prev = curr;
            curr = nextN;
            nextN = nextN->next;
        }
        curr->next = prev;
        list = curr;
        
    }
    void reorderList(Node* head) {
        if(head ==NULL || head->next == NULL) return;
        Node*mid = head;
        Node*fast = head->next;
        while(fast!=NULL && fast->next !=NULL){
            mid = mid->next;
            fast = fast->next->next;
        }
        Node* listend = mid->next;
        mid->next = NULL;
        reverseLL(listend);
        
        Node*temp = head;
        while(temp!=NULL && temp->next !=NULL){
            Node* t = temp->next;
            Node* curr = listend;
            if(listend!=NULL)listend = listend->next;
            temp->next = curr;
            curr->next = t;
            temp = temp->next->next;           
        }
        if(listend !=NULL){
            temp->next = listend;
            
        }
    }