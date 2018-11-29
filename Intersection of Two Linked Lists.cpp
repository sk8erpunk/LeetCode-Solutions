/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB){
            return NULL;
        }
        int len1 = 0,len2 = 0;
        ListNode* itr1 = headA, *itr2 = headB;   
        while(itr1 != NULL){
            len1++;
            itr1 = itr1->next;
        }
        while(itr2 != NULL){
            len2++;
            itr2 = itr2->next;
        }
        int steps = len1 > len2 ? len1 - len2 : len2 - len1;
        ListNode* ll = len1 > len2 ? headA : headB;
        ListNode* sl = len1 > len2 ? headB : headA;
        while(steps > 0){
            steps--;
            ll = ll->next;
        }
        while(ll != sl){    
            ll = ll->next;
            sl = sl->next;
        }
        return ll;
    }
};