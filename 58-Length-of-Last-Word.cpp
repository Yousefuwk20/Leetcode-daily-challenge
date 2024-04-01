class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        bool c = false;
        
        for (int i = s.length() - 1; i >= 0; --i){
            if (s[i] != ' ') {
                c = true;
                len++;
            }
            else if(c) break;
        }
        return len;
    }
};