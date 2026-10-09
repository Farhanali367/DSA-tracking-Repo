class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int open = 0;
        int close2 = 0;
        int ans = 0;
        int i = 0;

        while (i < n) {
            if (s[i] == '(') {
                open++;
                i++;
            } else {
                int close = 0;
                while (i < n && s[i] == ')') {
                    close++;
                    i++;
                }

                close2 += close / 2;

                if (close % 2) {
                    close2++;
                    ans++;
                }

                if (close2 > open) {
                    ans += close2 - open;
                    open = 0;
                    close2 = 0;
                } else {
                    open -= close2;
                    close2 = 0;
                }
            }
        }

        ans += 2 * open;

        return ans;
    }
};