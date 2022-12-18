https://leetcode.com/problems/implement-trie-prefix-tree/description/

class Trie {
private:

struct TrieNode{
    struct TrieNode *child[26];
    bool isEnd;
};

public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    TrieNode* getNode(){
        TrieNode *node = new TrieNode();
        node->isEnd = false;
        return node;
    }
    
    void insert(string word) {
        TrieNode *trav = root;
        for(int i = 0;i < word.size();i++){
            int idx = word[i]-'a';
            if(!trav->child[idx])
                trav->child[idx] = getNode();
            trav = trav->child[idx];
        }
        trav->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode *trav = root;
        for(int i = 0;i < word.size();i++){
            int idx = word[i]-'a';
            if(!trav->child[idx])
                return false;
            trav = trav->child[idx];
        }
        return trav->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *trav = root;
        for(int i = 0;i < prefix.size();i++){
            int idx = prefix[i]-'a';
            if(!trav->child[idx])
                return false;
            trav = trav->child[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
