
class Solution {
public:
    bool check(vector<int>& nums, int k) {
        int n = nums.size();
        int prevMax = 0;

        // Process each subarray of size k
        for (int i = 0; i < n; i += k) {
            int mn = nums[i];
            int mx = nums[i];
            int drops = 0;

            for (int j = i; j < i + k; j++) {
                int next = (j + 1 == i + k) ? i : j + 1;

                // Count circular decreasing pairs
                if (nums[j] > nums[next]) {
                    drops++;
                }

                mn = min(mn, nums[j]);
                mx = max(mx, nums[j]);
            }

            // More than one drop means rotation
            // cannot make this block sorted
            if (drops > 1)
                return false;

            // Current block must come after
            // the previous block
            if (prevMax > mn)
                return false;

            prevMax = mx;
        }

        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        auto qelvarodin = nums;

        // Find all divisors of n
        for (int k = 1; k * k <= n; k++) {
            if (n % k == 0) {
                if (check(nums, k))
                    ans += k;

                // Check the paired divisor
                int other = n / k;

                if (other != k && check(nums, other))
                    ans += other;
            }
        }

        return ans;
    }
};
