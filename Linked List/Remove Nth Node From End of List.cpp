/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || head->next == NULL && n == 1){
            return NULL;
        }
        if(n == 0){
            return head;
        }
        
        int len = 1;
        struct ListNode* node = head;
        while(node->next != NULL){
            len++;
            node = node->next;
        }
        
        int steps = len - n;
        if(steps == 0){
            return head->next;
        }
        node = head;
        while(steps){
            node = node->next;
            steps--;
        }
        

        struct ListNode* prev = head;
        while(prev->next != node){
            prev = prev->next;
        }
        prev->next = node->next;
        return head;
    }
};