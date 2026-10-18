
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int maxi = 0;

        // Iterate over unique elements only
        for (int num : st) {

            // Start only if the previous number doesn't exist
            if (num == INT_MIN || st.find(num - 1) == st.end()) {

                int count = 1;
                int current = num;

                // Count consecutive numbers
                while (current < INT_MAX &&
                       st.find(current + 1) != st.end()) {
                    current++;
                    count++;
                }

                // Update longest sequence
                maxi = max(maxi, count);
            }
        }

        return maxi;
    }
};
