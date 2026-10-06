class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, close = 0;
        int ans = 0;
        for (auto it : s) {
            if (it == '(')
                open++;
            else
                close++;

            if (close > open) {
                ans++;
                close--;
            }
        }
        ans += open - close;
        
        return ans;
    }
};