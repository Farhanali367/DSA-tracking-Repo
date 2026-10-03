class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0, close = 0;
        int ans = 0;

        // Left -> Right
        for (char c : s) {
            if (c == '(')
                open++;
            else
                close++;

            if (open == close) {
                ans = max(ans, 2 * close);
            } else if (close > open) {
                open = 0;
                close = 0;
            }
        }

        // Right -> Left
        open = 0;
        close = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(')
                open++;
            else
                close++;

            if (open == close) {
                ans = max(ans, 2 * open);
            } else if (open > close){
                open = 0;
                close = 0;
            }
        }

        return ans;
    }
};