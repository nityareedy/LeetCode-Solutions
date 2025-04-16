/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // int num1=0;
        // while(l1!=NULL){
        //     num1=num1*10+l1->val;
        //     l1=l1->next;
        // }
        // int num2=0;
        // while(l2!=NULL){
        //     num2=num2*10+l2->val;
        //     l2=l2->next;
        // }
        // num1=num1+num2;
        // int rem=num1%10;
        // ListNode *ans=new ListNode(rem);
        // ListNode *dup=ans;
        // num1=num1/10;
        // while(num1>0){
        //     rem=num1%10;
        //     ListNode *temp=new ListNode(rem);
        //     ans->next=temp;
        //     ans=ans->next;
        // }
        ListNode *dummy= new ListNode();
        ListNode *ans= dummy;
        int sum=0;
        int carry=0;
        while(l1!=NULL||l2!=NULL){
            sum=carry;
            carry=0;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            if(sum>=10){
                carry=1;
                sum=sum%10;
               
            }
             ListNode *temp= new ListNode(sum);
                dummy->next=temp;
                dummy=dummy->next;

        }
        if(carry==1){
             ListNode *temp= new ListNode(1);
                dummy->next=temp;
                dummy=dummy->next;
        }
        return ans->next;
        
    }
};
