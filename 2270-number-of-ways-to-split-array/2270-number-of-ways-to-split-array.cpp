class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        long long total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        long long sum1=0;
        for(int i=0;i<n-1;i++){
            sum1+=nums[i];         // Include this element in the left side
            long long sum2 = total - sum1; // running prefix sum
            if(sum1>=sum2){
                count++;
            }
        }
        return count;
    }
};