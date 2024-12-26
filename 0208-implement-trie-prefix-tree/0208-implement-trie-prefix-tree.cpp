class TrieNode {
public:
    bool isLeaf;
    TrieNode* child[26];

    TrieNode() {
        isLeaf = false;
        for(int i=0; i<26; i++){
            child[i] = NULL;
        }
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cnode = root;
        for(auto c: word){
            int i = c-'a';
            if(cnode->child[i]==NULL){
                TrieNode* nd = new TrieNode();
                cnode->child[i] = nd;
            }
            cnode = cnode->child[i];
        }
        cnode->isLeaf = true;
    }
    
    bool search(string word) {
        TrieNode* cnode = root;
        for(auto c: word){
            int i = c-'a';
            if(cnode->child[i]==NULL)   return false;
            cnode = cnode->child[i];
        }
        return cnode->isLeaf;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cnode = root;
        for(auto c: prefix){
            int i = c-'a';
            if(cnode->child[i]==NULL)   return false;
            cnode = cnode->child[i];
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