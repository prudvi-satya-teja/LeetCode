class Solution {
public:

    class Trie {
        public: 
            Trie* children[10];
            bool isEnd;

            Trie() {
                for(int i=0; i<10; i++) {
                    children[i] = NULL;
                }
                
                isEnd = false;
            }
    };

    Trie* head = new Trie();

    void insert(string str) {
        Trie* curr = head;

        for(int i=0; i<str.size(); i++) {
            int ch = str[i] - '0';

            if(curr->children[ch] == NULL) {
                curr->children[ch] = new Trie();
            }
            curr = curr->children[ch];
        }

        curr->isEnd = true;
    }

    int search(string str) {
        Trie* curr = head;

        for(int i=0; i<str.size(); i++) {
            int ch = str[i] - '0';
            if(curr->children[ch] == NULL) {
                return i;
            }
            else {
                curr = curr->children[ch];
            }
        }
        return str.size();
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        for(int i=0; i<arr1.size(); i++) {
            int ele = arr1[i];
            string num = to_string(ele);
            insert(num);
        }

        int mx = 0;

        for(int i=0; i<arr2.size(); i++) {
            int ele = arr2[i];
            string num = to_string(ele);
            mx =max(mx, search(num));
        }
        return mx;
    }
};