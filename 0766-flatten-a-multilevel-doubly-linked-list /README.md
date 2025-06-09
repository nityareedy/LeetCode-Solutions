/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *ans=head;
        while(head!=NULL){
            if(head->child==NULL){
                head=head->next;
            }
            else{

            
            Node *next=head->next;
            Node *child=head->child;
            child->prev=head;
            head->next=child;
            head->child=NULL;
            Node *prev=head;
            while(child!=NULL){
                if(child->child==NULL){
                    prev=child;
                    child=child->next;
                }
                else{
                    flatten(child);
                }


            }

            prev->next=next;
            if(next!=NULL){

            next->prev=prev;
            }

            
            head=prev->next;
            }
            // if(prev!=NULL){

            // head->prev=prev;
            // }
        }
        return ans;
    }
};
