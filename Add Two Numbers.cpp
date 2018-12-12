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
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* add(ListNode* l1, ListNode* l2, int carry){
        if(!l1 && !l2 && carry == 0) return NULL;
        int sum = carry;
        if(l1)
            sum += l1->val;
        if(l2)
            sum += l2->val;
        ListNode* res;
        if(sum > 9){
            res = new ListNode(sum%10);
            carry = 1;
        } else {
            res = new ListNode(sum);
            carry = 0;
        }
        ListNode* node = add(l1 != NULL ? l1->next : NULL, l2 != NULL ? l2->next : NULL, carry);
        res->next = node;
        return res;
        
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1,l2,0);
    }
};