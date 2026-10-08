class Solution {
public:
    string removeOuterParentheses(string str) {
        string ans = "";
        int cnt = 0;

        for (char ch : str) {
            if (ch == '(' && cnt++ > 0) {
                ans += ch; // Append only if it's not the outer '('
            }
            if (ch == ')' && --cnt > 0) {
                ans += ch; // Append only if it's not the outer ')'
            }
        }

        return ans;
    }
};