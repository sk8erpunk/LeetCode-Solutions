/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* add(struct ListNode* l1, struct ListNode* l2, int carry) {
    if(l1 == NULL && l2 == NULL){
        if(carry){
            struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
            node->val = carry;
            node->next = NULL;
            return node;
        }
        return NULL;
    }
    
    struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));
    int value = carry;
    if(l1 != NULL){
        value += l1->val;
    }
    if(l2 != NULL){
        value += l2->val;
    }
    result->val = value % 10;
    struct ListNode* more = add(l1 == NULL ? NULL : l1->next, l2 == NULL ? NULL : l2->next, value >= 10 ? 1 : 0);
    result->next = more;
    return result;
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    return add(l1,l2,0);
} 