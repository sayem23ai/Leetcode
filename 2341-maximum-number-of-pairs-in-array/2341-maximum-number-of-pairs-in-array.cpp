class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans(2);
        int count = 0;
        int pair = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i + 1 < nums.size() && nums[i] == nums[i+1]) {
                pair++;
                i++;
                continue;
            }
            else {
                count++;
            }
        }
        ans[0] = pair;
        ans[1] = count;
        return ans;
    }
};
