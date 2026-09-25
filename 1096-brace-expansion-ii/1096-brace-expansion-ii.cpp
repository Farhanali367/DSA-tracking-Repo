class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        set<string> s; 
        queue<string> q;
        q.push(expression);

        while (!q.empty()) {
            string temp = q.front();
            q.pop();
            // right: the index of the '}' (nearest the index of string from
            // left to right) left: the index of the '{', but it nearest the
            // index of the '}'
            // {{a,{b,c}}}
            // => right: 8
            // => left : 4 (not 1 because of nearest the right index)
            int left = -1, right = 0;
            // find the { first in the string
            while (right < temp.length() && temp[right] != '}') {
                if (temp[right] == '{')
                    left = right;
                right++;
            }

            // circumtances that the string temp had been remove {}, so left is
            // -1 save the result example: a   or   b   or   c
            if (left == -1) {
                s.insert(temp);
                continue;
            }

            // {{a,{b,c}}}
            // first step:
            // start: {{a,      (we had removed '{')
            // end: }}
            // mid: b,c
            string start = temp.substr(0, left);
            string end = temp.substr(right + 1);
            string mid = temp.substr(left + 1, right - left - 1);

            // if we had ',' => split and push to vector words
            // example
            // mid we had: b,c
            // => words vector(2 element): b c
            vector<string> words;
            stringstream ss(mid);
            string tmp;
            while (getline(ss, tmp, ',')) {
                words.push_back(tmp);
            }

            // after removing {}, we had 2 circumtances:
            // 1.  {{a,b}}
            // 2.  {{a,c}}
            for (string middle : words) {
                q.push(start + middle + end);
            }
        }
        vector<string> result(s.begin(), s.end());
        return result;
    }
};