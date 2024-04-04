class Solution {
public:
    int maxDepth(string s) {
        int count{}, max_num{};
        for (char c : s) {
            if (c == '('){
                count++;
                if (max_num < count) max_num = count;
            }
            else if (c == ')') count--;
        }
        return max_num;
    }
};