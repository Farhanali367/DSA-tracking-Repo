class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int med = nums[n / 2];

        int ans = 0;
        for (auto it : nums) {
            ans += abs(med - it);
        }

        return ans;
    }
};