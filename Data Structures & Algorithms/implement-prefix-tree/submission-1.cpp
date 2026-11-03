struct Node {
    bool isWord; 
    vector<Node*> letters;
    Node() {
        isWord = false; 
        for (int i = 0; i < 26; i++) {
            letters.push_back(nullptr);
        }
    }
};

class PrefixTree {
public:
    Node* root;
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root; 
        for (int i = 0; i < word.length(); i++) {
            if(!curr->letters[word[i]-'a']) curr->letters[word[i]-'a'] = new Node();
            curr = curr->letters[word[i]-'a'];
        }
        curr->isWord = true; 
    }
    
    bool search(string word) {
        Node* curr = root; 
        for (int i = 0; i < word.length(); i++) {
            if(!curr->letters[word[i]-'a']) return false; 
            curr = curr->letters[word[i]-'a'];
        }
        return curr->isWord;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root; 
        for (int i = 0; i < prefix.length(); i++) {
            if(!curr->letters[prefix[i]-'a']) return false; 
            curr = curr->letters[prefix[i]-'a'];
        }
        return true; 
    }
};
