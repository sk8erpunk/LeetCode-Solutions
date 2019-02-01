/*
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:
Input: 4->2->1->3
Output: 1->2->3->4

Example 2:
Input: -1->5->3->4->0
Output: -1->0->3->4->5
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
    ListNode* swap(ListNode* head1, ListNode* head2){
        int tmp = head1->val;
        head1->val = head2->val;
        head2->val = tmp;
        return head1;
    }

    ListNode* merge(ListNode* head1, ListNode* head2){
        if(!head1) return head2;
        if(!head2) return head1;

        ListNode* itr1 = head1->val <= head2->val ? head1 : head2;
        ListNode* itr2 = head1->val <= head2->val ? head2 : head1;

        ListNode* prev = NULL;

        while(itr1 && itr2){
            if(itr1->val > itr2->val){
                ListNode* tmp = itr2->next;
                prev->next = itr2;
                itr2->next = itr1;
                prev = prev->next;
                itr2 = tmp;
                continue;
            } 
            prev = itr1;
            itr1 = itr1->next;
        }
        if(!itr1 && itr2){
            prev->next = itr2;
        }
        ListNode* head = head1->val <= head2->val ? head1 : head2;
        return head;
    }
    
    ListNode* sort(ListNode* head){
        if(!head->next) 
            return head;
        else if(!head->next->next){
            if(head->val > head->next->val){
                return swap(head,head->next);
            } else {
                return head;
            }
        }
        
        ListNode* p1 = head, *p2 = head;
        while(p2 && p2->next){
            p1 = p1->next;
            p2 = p2->next->next;
        }
        p2 = p1;        // middle
        p1 = head;
        while(p1->next != p2){
            p1 = p1->next;
        }
        p1->next = NULL;
        p1 = head;
        ListNode* sorted1 = sort(p1);
        ListNode* sorted2 = sort(p2);
        ListNode* merged = merge(sorted1,sorted2);
        return merged; 
        
    }
    ListNode* sortList(ListNode* head) {
        if(!head) return NULL;
        return sort(head);
    }
};