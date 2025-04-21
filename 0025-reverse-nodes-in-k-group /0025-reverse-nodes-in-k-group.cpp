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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *toFindLength=head;
        int count=0;
        while(toFindLength!=NULL){
            count++;
            toFindLength=toFindLength->next;
        }        
        ListNode *ans=new ListNode(0);
        ans->next=head;
        ListNode *pre = ans;
        while(count>=k){
            ListNode *current=pre->next;
            ListNode *next=current->next;
            for(int i=0;i<k-1;i++){
                current->next=next->next;
                next->next=pre->next;
                pre->next=next;
                next=current->next;
            }
            for(int i=0;i<k;i++){
                pre=pre->next;
                count--;
            }


        }

        return ans->next;

        
    }
};
