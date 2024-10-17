class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        string str2 = str;
        sort(str.rbegin(), str.rend());

        char ch = 'a';
        char req = 'a';
        for(int i=0; i<str.size(); i++) {
            if(str[i] != str2[i]) {
                ch = str2[i];
                req = str[i];
                str2[i] = req;
                break;
            }
        }

        if(ch != 'a') {
            for(int i=str2.size()-1; i>=0; i--) {
                if(str2[i] == req)  {
                    str2[i] = ch;
                    break;
                }
            }
        }        

        return stoi(str2);
    }
};