class Solution {
public:
    string solve(string &s, int i, int j) {
        string ans = "";

        while (i <= j) {

            // Normal character
            if (s[i] != '(') {
                if (s[i] != ')')
                    ans += s[i];
                i++;
            }

            // Found '('
            else {
                int cnt = 1;
                int k = i + 1;

                // Find matching ')'
                while (k <= j && cnt > 0) {
                    if (s[k] == '(')
                        cnt++;
                    else if (s[k] == ')')
                        cnt--;

                    k++;
                }

                // k-1 is the matching ')'
                string temp = solve(s, i + 1, k - 2);

                reverse(temp.begin(), temp.end());

                ans += temp;

                // Continue after ')'
                i = k;
            }
        }

        return ans;
    }

    string reverseParentheses(string s) {
        return solve(s, 0, s.size() - 1);
    }
};