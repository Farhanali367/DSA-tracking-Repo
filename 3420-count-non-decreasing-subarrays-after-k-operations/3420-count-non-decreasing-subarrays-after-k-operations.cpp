constexpr int N = 1e5;
int dq[N], front, back;
using ll = long long;

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        const int n = nums.size();
        front = back = n; // 
        ll cnt = 0, op = 0;
        for (int r = n - 1, l = n - 1; l >= 0; l--) {
            const int x = nums[l];
            // prefix max
            while (front < back && x >= nums[dq[front]]) {
                int j = dq[front++];
                int next_idx = (front == back) ? (r + 1) : dq[front];
                op += (ll)(next_idx - j) * (x - nums[j]);
            }
            dq[--front] = l;

            //  right while op exceeds k
            while (op > k) {
                op -= (nums[dq[back - 1]] - nums[r]);
                if (dq[back - 1] == r)
                    back--;
                r--;
            }
            // Subarrays nums[l..i] for i in [l, r] are all valid
            cnt += (r - l + 1);
        }
        return cnt;
    }
};