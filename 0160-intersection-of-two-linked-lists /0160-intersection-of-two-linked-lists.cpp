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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // if(headA==headB){
        //     return headA;
        // }
        // ListNode *b=headB;
        // ListNode *a=headA;

        // while(headA!=NULL){
        //     headB=b;
            
        //     while(headB!=NULL){

        //     if(headA==headB){
        //         return headA;
        //     }
        //     headB=headB->next;
        //     }
        //     headA=headA->next;
        // }

        //  headB=b;
        //  cout<<headB->val<<endl;
        //  while(headB!=NULL){
        //      cout<<"here"<<endl;
        //     headA=a;
            
        //     while(headA!=NULL){

        //     if(headA->next==headB->next){
        //         return headB->next;
        //     }
        //     headA=headA->next;
        //     }
        //     headB=headB->next;
        // }

        ListNode *a= headA;
        ListNode *b= headB;
        while(a!=b){
            if(a!=NULL) a=a->next;
            else a=headB;
            if(b!=NULL) b=b->next;
            else b=headA;
        }
        return a;
        
        
    }
};
