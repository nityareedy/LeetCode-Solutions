/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // ListNode *dup=head;
        // ListNode *test=head;

        // while(head!=NULL){
        //     while(dup!=NULL){
        //         if(dup->next==head){

        //         }


        //     }
        // }
        // return false;
    //  
    if(head==NULL || head->next==NULL){
        return false;
    }
    ListNode *single=head;
    ListNode *two=head;
    while(two->next!=NULL && two->next->next!=NULL){
        two=two->next->next;
        single=single->next;
        if(single==two){
            return true;
        }
        
    }
    return false;
    }
};
