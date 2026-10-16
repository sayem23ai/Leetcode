class Solution {
    static constexpr long long MOD = 1000000007;
    int n;
    vector<long long> bit1, bit2;

    void add(vector<long long>& bit, int i, long long value) {
        for (; i <= n; i += i & -i) {
            bit[i] += value;
        }
    }

    long long query(const vector<long long>& bit, int i) {
        long long sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += bit[i];
        }
        return sum;
    }

    void rangeAdd(int left, int right) {
        add(bit1, left, 1);
        add(bit1, right + 1, -1);

        add(bit2, left, left - 1);
        add(bit2, right + 1, -right);
    }

    long long prefixSum(int i) {
        return query(bit1, i) * i - query(bit2, i);
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        bit1.assign(n + 1, 0);
        bit2.assign(n + 1, 0);

        vector<int> last(100001, 0);
        long long current = 0;
        long long answer = 0;

        for (int right = 1; right <= n; right++) {
            int value = nums[right - 1];
            int left = last[value] + 1;

            long long sum = prefixSum(right) - prefixSum(left - 1);

            current = (current + 2 * sum + right - left + 1) % MOD;
            answer = (answer + current) % MOD;

            rangeAdd(left, right);
            last[value] = right;
        }

        return static_cast<int>(answer);
    }
};