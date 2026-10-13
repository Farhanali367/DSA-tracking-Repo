class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end(), greater<int>());

        int cnt = n / 2;
        if (n % 2)
            cnt++;

        for (int i = 0; i < cnt; i++)
            ans += nums[i] * nums[i];
        for (int i = cnt; i < n; i++)
            ans -= nums[i] * nums[i];

        return ans;
    }
};