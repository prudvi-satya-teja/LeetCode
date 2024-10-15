class Solution {
public:
    long long minimumSteps(string s) {
        
        long long k = s.size();
        long long count = 0;

        int zerocnt = 0;
        for(int i=0; i<s.size(); i++) {
            char ch = s[i];
            if(ch == '0') {
                zerocnt++;
            }
        }    

        priority_queue<int> pq;

        for(int i=zerocnt-1; i<s.size(); i++) {
            char ch = s[i];
            if(ch == '0') {
                pq.push(i);
            }
        }

        for(int i=zerocnt-1; i>=0; i--) {
            char ch = s[i];
            if(ch == '1') {
                int top = pq.top();
                pq.pop();   
                count = count + (top - i);  
            }
        }

        return count;
        
    }
};