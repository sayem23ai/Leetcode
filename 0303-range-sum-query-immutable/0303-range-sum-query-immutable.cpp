class NumArray {
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        int n=nums.size();
        prefix.resize(n + 1, 0);
        // prefix[i + 1] stores the sum from index 0 through i.
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
    }
    int sumRange(int left,int right) {
        // Remove the sum of elements before left.
        return prefix[right+1]-prefix[left];
    }
};