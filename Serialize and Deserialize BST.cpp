/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.
The encoded string should be as compact as possible.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void buildTree(TreeNode* root, int val){
        if(val < root->val){
            if(root->left == NULL)
                root->left = new TreeNode(val);
            else
                buildTree(root->left, val);
        } else {
            if(root->right == NULL)
                root->right = new TreeNode(val);
            else
                buildTree(root->right,val);
        }
    }
    
    void preOrder(TreeNode* root, string& res){
        if(root){
            res += to_string(root->val) + "#";
            preOrder(root->left,res); 
            preOrder(root->right,res); 
        }
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string res = "";
        preOrder(root,res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        vector<int> v;
        string num = "";
        for(int i = 0; i < data.size(); i++){
            if(data[i] != '#')
                num += data[i];
            else if(num != "") {
                v.push_back(stoi(num));
                num = "";
            }
        }
        TreeNode* root = new TreeNode(v[0]);
        for(int i = 1; i < v.size(); i++)
            buildTree(root, v[i]);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));