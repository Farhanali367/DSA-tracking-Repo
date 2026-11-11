class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {

        long long ans = 0;

        // Option 1: Buy items separately
        ans = 1LL * cost1 * need1 + 1LL * cost2 * need2;

        // Option 2: Buy common items using costBoth
        int common = min(need1, need2);

        long long temp = 1LL * common * costBoth;

        temp += 1LL * (need1 - common) * cost1;
        temp += 1LL * (need2 - common) * cost2;

        ans = min(ans, temp);
        temp = 1LL * max(need1, need2) * costBoth;

        ans = min(ans, temp);

        return ans;
    }
};