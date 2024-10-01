class Trie {
public:
    class TrieNode {
        public: 
        TrieNode* children[26];
        bool isEnd;

        TrieNode() {
            for(int i=0; i<26; i++) {
                children[i] = NULL;
            }
            isEnd = false;
        }

    };

    TrieNode* head;

    Trie() {
       head = new TrieNode();
    }

    
    void insert(string word) {
        TrieNode* curr = head;
        for(int i=0; i<word.size(); i++) {
            int ch = word[i] - 'a';
            if(curr->children[ch] == NULL ) {
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = head;
        for(int i=0; i<word.size(); i++) {
            int ch = word[i] - 'a';
            if(curr->children[ch] == NULL ) {
                return false;
            }
            curr = curr->children[ch];
        }
        return curr->isEnd;
        
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = head;
        for(int i=0; i<prefix.size(); i++) {
            int ch = prefix[i] - 'a';
            if(curr->children[ch] == NULL ) {
                return false;
            }
            curr = curr->children[ch];
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