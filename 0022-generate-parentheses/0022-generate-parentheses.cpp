class Solution {
public:
    void solve(int idx, int n, string s, int open, int close,
               vector<string>& ans) {

        if (idx == 2 * n) {
            ans.push_back(s);
            return;
        }

        if (open < n) {
            solve(idx + 1, n, s + '(', open + 1, close, ans);
        }

        if (close < open) {
            solve(idx + 1, n, s + ')', open, close + 1, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0, n, "", 0, 0, ans);
        return ans;
    }
};