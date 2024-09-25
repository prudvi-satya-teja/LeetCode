class Solution {
public:

    class Trie {
        public: 
        Trie* children[26];
        int freq = 0;

        Trie() {
            for(int i=0; i<26; i++) {
                children[i] = NULL;
            }
            freq = 0;
        }
    };

    Trie* head = new Trie();

    void insert(string str) {
        Trie* curr = head;

        for(int i=0; i<str.size(); i++) {
            int ch = str[i] - 'a';
            if(curr->children[ch] == NULL) {
                curr->children[ch] = new Trie(); 
            }
            
            curr->children[ch]->freq += 1;
            curr = curr->children[ch];
        }
    }

    int search(string str) {
        int count = 0;

        Trie* curr = head;
        for(int i=0; i<str.size(); i++) {
            int ch = str[i] -  'a';
            
            if(curr->children[ch] == NULL) {
                return count;
            }

            count = count + curr->children[ch]->freq;
            curr = curr->children[ch];

        }
        return count;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        for(int i=0; i<words.size(); i++) {
            insert(words[i]);
        }

        vector<int> v;
        for(int i=0; i<words.size(); i++) {
            v.push_back(search(words[i]));
        }
        return v;

        
    }
};