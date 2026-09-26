 class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
        int n = s.size();
        unordered_map<string, string> mpp;
        for (auto it : k) {
            mpp[it[0]] = it[1];
        }

        string ans = "";

        for (int i = 0; i < n; i++) {
            if (s[i] != '(' && s[i] != ')') {
                ans += s[i];
                continue;
            }

            string temp = "";
            if (s[i] == '(') {
                i++;
                string key = "";
                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }
                if (mpp.count(key))
                    ans += mpp[key];
                else
                    ans += '?';
            }
        }

        return ans;
    }
};