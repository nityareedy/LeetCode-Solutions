/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head==NULL) return NULL;

        Node *temp=head;
        while(temp!=NULL){
            Node *newNode= new Node(temp->val);
            Node *next= temp->next;
            temp->next=newNode;
            temp->next->next=next;
            temp=temp->next->next;
        }
        temp=head;
        while(temp!=NULL){
            if(temp->random==NULL){
                temp->next->random=NULL;
            }
            else{
                temp->next->random=temp->random->next;
            }
            temp=temp->next->next;
        }
        
        temp=head;
        Node *copy=temp->next;
        while(temp!=NULL && temp->next!=NULL){
            Node *next= temp->next;
            temp->next=temp->next->next;
            temp=next;
          

        }
    
       
        return copy;
    }
};
