/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* head = new ListNode(0);
        head->next = NULL;
        ListNode* it1 = l1, *it2 = l2;
        ListNode *it = head;
        
        while(it1 != NULL && it2 != NULL){
            int val;
            if(it1->val <= it2->val){
                val = it1->val;
                it1 = it1->next;
            } else {
                val = it2->val;
                it2 = it2->next;
            }

            ListNode* node = new ListNode(val);
            it->next = node;
            it = it->next;
            
        }

        ListNode* rest = it1 == NULL ? it2 : it1;
        while(rest != NULL){
            ListNode* node = new ListNode(rest->val);
            it->next = node;
            it = it->next;
            rest = rest->next;
        }
        return head->next;
    }
};