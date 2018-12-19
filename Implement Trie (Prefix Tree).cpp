/*
Implement a trie with insert, search, and startsWith methods.

Example:
Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/

#define ALPHABET_SIZE 26

struct TrieNode {
    TrieNode* children[ALPHABET_SIZE];
    int isEnd;
    TrieNode() {
        isEnd = false;
        for(int i = 0; i < ALPHABET_SIZE; i++)
            children[i] = NULL;
    }
};

class Trie {
    TrieNode* root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* itr = root;
        for(int i = 0; i < word.size(); i++){
            if(!itr->children[word[i]-'a']) // if doesnt exist
               itr->children[word[i]-'a'] = new TrieNode();
            itr = itr->children[word[i]-'a'];
        }
        itr->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* itr = root;
        for(int i = 0; i < word.size(); i++){
            if(itr->children[word[i] - 'a'])
                itr = itr->children[word[i]-'a'];
            else
                return false;
        }
        return itr != NULL && itr->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* itr = root;
        for(int i = 0; i < prefix.size(); i++){
            if(itr->children[prefix[i] - 'a'])
                itr = itr->children[prefix[i]-'a'];
            else
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */