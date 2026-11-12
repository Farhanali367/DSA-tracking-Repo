class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        int len = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                len++;
                ans = max(ans, len);
            } else
                len = 1;
        }
        len = 1;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] < nums[i - 1]) {
                len++;
                ans = max(ans, len);
            } else
                len = 1;
        }
        return ans;
    }
};