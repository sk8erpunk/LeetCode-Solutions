/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) 
            return NULL;
        ListNode* head = new ListNode(0); // head;
        ListNode* itr = head;
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i = 0 ; i < lists.size(); i++){
            if(lists[i])
                pq.push(make_pair(lists[i]->val, i));
        }
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();
            int val = p.first;
            int nodeIdx = p.second;
            itr->next = new ListNode(val);    
            itr = itr->next;
            lists[nodeIdx] = lists[nodeIdx]->next;
            if(lists[nodeIdx])
                pq.push(make_pair(lists[nodeIdx]->val, nodeIdx));
        }
        return head->next;
    }
};