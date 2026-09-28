class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0, ans = 0;
        for (auto it : s) {
            if (it == '(') {
                cnt ++;
                ans = max(cnt, ans);
            } else if (it == ')')
                cnt--;
        }

        return ans;
    }
};