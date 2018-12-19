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
    unordered_map<TreeNode*,TreeNode*> parent;
    TreeNode* curr;
    
public:
    void findParents(TreeNode* p, TreeNode* n){
        parent[n] = p;
        if(n->left)
            findParents(n, n->left);
        if(n->right)
            findParents(n, n->right);
    }
    
    BSTIterator(TreeNode *root) {
        if(!root){
            curr = NULL;
            return;
        }
        findParents(NULL,root);
        while(root->left) // initialize the first smallest
            root = root->left;
        curr = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return curr != NULL;
    }

    /** @return the next smallest number */
    int next() {
        int res = curr->val; // curr saves next element
        // update curr to next element
        if(curr->right){   // if it has right find leftest element
            curr = curr->right;
            while(curr->left)
                curr = curr->left;
        } else { // go up until you are a left son
            while(parent[curr] && curr == parent[curr]->right) 
                curr = parent[curr];
            curr = parent[curr];
        }
        return res;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */