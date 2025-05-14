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
    bool isPalindrome(ListNode* head) {
       ListNode *fast=head;
       ListNode *slow=head;
       while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
       }
        ListNode *newLink=NULL;
        slow=slow->next;
        while(slow!=NULL){
            ListNode *next=slow->next;
            slow->next=newLink;
            newLink=slow;
            slow=next;

        }
        while(newLink!=NULL){
            if(newLink->val!=head->val) return false;
            cout<<newLink->val<<endl;
            cout<<head->val<<endl;
            newLink=newLink->next;
            head=head->next;
        }
       return true;
    }
};
