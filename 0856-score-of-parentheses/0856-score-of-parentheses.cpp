class Solution {
public:
    int scoreOfParentheses(string s) {
        int depth = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                depth++;
            } else {
                depth--;

                // Direct "()" pair
                if (s[i - 1] == '(') {
                    ans += 1 << depth;
                }
            }
        }

        return ans;
    }
};