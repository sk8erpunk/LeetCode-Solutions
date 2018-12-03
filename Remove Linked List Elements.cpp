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
        if(!head)
            return NULL;
        
        //special case
        while(head && head->val == val){
            head = head->next;
        }
        
        //  head doesnt has val for sure
        ListNode* prev = NULL, *curr = head;
        while(curr){
            if(curr->val == val)
                prev->next = curr->next;
            else 
                prev = curr;
            curr = curr->next;
        }
        return head;
    }
};