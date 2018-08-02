/*
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5

*/

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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head){
            return NULL;
        }
        
        //special case
        while(head->val == val){
            head = head->next;
            if(!head){
                return head;                
            }
        }
        
        ListNode* itr = head->next;
        ListNode* prev = head;
        while(itr != NULL){
            if(itr->val == val){
                prev->next = itr->next;
                itr = prev->next;
            } else {
                itr = itr->next;
                prev = prev->next;   
            }
        }
        return head;
    }
};