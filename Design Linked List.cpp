/*
Design your implementation of the linked list. You can choose to use the singly linked list or the doubly linked list. A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node. If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement these functions in your linked list class:

get(index) : Get the value of the index-th node in the linked list. If the index is invalid, return -1.
addAtHead(val) : Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
addAtTail(val) : Append a node of value val to the last element of the linked list.
addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.
Example:

MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
linkedList.get(1);            // returns 2
linkedList.deleteAtIndex(1);  // now the linked list is 1->3
linkedList.get(1);            // returns 3
Note:

All values will be in the range of [1, 1000].
The number of operations will be in the range of [1, 1000].
Please do not use the built-in LinkedList library.
*/

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x) , next(NULL) {}
};

class MyLinkedList {
    Node* head;
    int length;
    
public:
    /** Initialize your data structure here. */
    MyLinkedList() : head(NULL), length(0) {
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= length || index < 0)
            return -1;
        
        Node* itr = head;
        while(itr != NULL){
            if(index == 0)
                return itr->val;
            itr = itr->next;
            index--;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* newHead = new Node(val);
        newHead->next = head;
        head = newHead;
        length++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* elem = new Node(val);
        if(!head){
            head = elem;
        } else {
            Node* itr = head;
            while(itr->next != NULL)
                itr = itr->next;
            itr->next = elem;
        }
        length++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > length) return;
        if(index == length){
            addAtTail(val);
        } else if(index == 0){
            addAtHead(val);
        } else {
            Node* itr = head;
            int count = 1;
            while(count < index){
                count++;
                itr = itr->next;
            }
            Node* elem = new Node(val);
            elem->next = itr->next;
            itr->next = elem;
            length++;  
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= length || index < 0) return;
        if(index == 0){
            head = head->next;
        } else {
            Node* itr = head;
            int count = 1;
            while(count < index){
                itr = itr->next;
                count++;
            }
            itr->next = itr->next->next;
        }
        length--;
    }
};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */