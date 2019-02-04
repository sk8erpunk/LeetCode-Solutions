/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> nextStack;     

    void pushNext(TreeNode* node){
        while(node){
            nextStack.push(node);
            node = node->left;
        }
    }
    
public:
    BSTIterator(TreeNode *root) {
        if(root)
            pushNext(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !nextStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* next = nextStack.top();
        nextStack.pop();
        pushNext(next->right);
        return next->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */