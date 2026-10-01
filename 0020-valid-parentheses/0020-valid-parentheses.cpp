class Solution {
public:
    bool isValid(string s) {
        map<char, char> mpp;
        mpp['('] = ')';
        mpp['{'] = '}';
        mpp['['] = ']';

        stack<char> st;
        for (auto it : s) {
            if (mpp[it])
                st.push(it);
            else if (!st.empty() && mpp[st.top()] == it)
                st.pop();
            else
                return false;
        }
        return st.empty();
    }
};