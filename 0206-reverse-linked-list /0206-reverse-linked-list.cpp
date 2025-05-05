/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(NULLptr) {}
 *     ListNode(int x) : val(x), next(NULLptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

      ListNode *newLink = NULL;
      while(head!=NULL){
        ListNode *next= head->next;
        head->next=newLink;
        newLink=head;
        head=next;
      }
      return newLink;
    }
};
