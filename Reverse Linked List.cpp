/*
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
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
    ListNode* reverseHead = NULL;   // to save head of reverse list
public:
    //Aux recursive function
    ListNode* reverse(ListNode* head){
        if(!head->next){
            reverseHead = head;
            return head; // reached last 
        } 
        ListNode* node = reverse(head->next);
        node->next = head;
        return head;
    }
     // Recursive Solution
    ListNode* reverseList(ListNode* head) {
        if(!head) return reverseHead;
        ListNode* node = reverse(head);
        node->next = NULL; // update head->next to NULL
        return reverseHead;
    }
    
    
    /* Iterative solution */
    // ListNode* reverseList(ListNode* head) {
    //     if(!head) return NULL;
    //     ListNode* prev = NULL;
    //     ListNode* curr = head;
    //     ListNode* next = curr->next;
    //     while(curr){
    //         curr->next = prev;
    //         prev = curr;
    //         curr = next;
    //         next = curr ? curr->next : NULL;
    //     }
    //     return prev;
    // }
};