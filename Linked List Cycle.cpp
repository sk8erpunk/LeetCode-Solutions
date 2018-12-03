/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
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
    bool hasCycle(ListNode *head) {
        // Using two pointers, one faster than the other.
        ListNode *pSlow = head, *pFast = head;
        while(pFast && pFast->next){
            pSlow = pSlow->next;
            pFast = pFast->next->next;
            if(pSlow == pFast) // if they meet then there is a cycle
                return true;
        }
        return false;
    }
};