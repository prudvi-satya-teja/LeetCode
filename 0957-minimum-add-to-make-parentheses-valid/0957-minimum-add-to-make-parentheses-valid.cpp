class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int count = 0;
        for(int i=0; i<s.size(); i++) {
            char ch = s[i];
            if(ch == '(') {
                st.push(ch);
            }
            else {
                if(st.empty()) {
                    count++;
                }
                else  {
                    st.pop();
                }
            }
        }
        return count + st.size();
        
    }
};