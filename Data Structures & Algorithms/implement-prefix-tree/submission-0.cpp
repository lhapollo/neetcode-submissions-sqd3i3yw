class PrefixTree {
private: 
    class TrieNode {
        public: 
            vector<TrieNode*> children;
            bool end_word; 
            TrieNode(){
                children = vector<TrieNode*>(26, nullptr);
                end_word = false;
            }
    };

public:
    TrieNode* root = new TrieNode();
    TrieNode* curr = root; 
    PrefixTree() {        

    }
    
    void insert(string word) {
        curr = root;
        for (int i = 0; i < word.length(); i++) {
            if (curr->children[word[i]-'a'] == nullptr) {
                curr->children[word[i]-'a'] = new TrieNode();
            }
            curr = curr->children[word[i]-'a'];
        }
        curr->end_word = true;
    }
    
    bool search(string word) {
        curr = root;
        for (int i = 0; i < word.length(); i++) {
            if (curr->children[word[i]-'a'] == nullptr) return false;
            if (i == word.length()-1) return curr->children[word[i]-'a']->end_word;
            else curr = curr->children[word[i]-'a'];
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        curr = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (curr->children[prefix[i]-'a'] == nullptr) return false;
            if (i == prefix.length() - 1) return true;
            else curr = curr->children[prefix[i]-'a'];
        }
        return false;
    }
};
