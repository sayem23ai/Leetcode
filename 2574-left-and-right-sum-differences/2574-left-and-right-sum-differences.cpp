class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> leftsum;
        vector<int> rightsum;
        leftsum.push_back(0);
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            sum+=nums[i];
            leftsum.push_back(sum);
        }
        sum=0;
        for(int i=nums.size()-1;i>0;i--){
            sum+=nums[i];
            rightsum.push_back(sum);
        }
        reverse(rightsum.begin(),rightsum.end());
        rightsum.push_back(0);
        vector<int> ans;
        for(int i=0;i<leftsum.size();i++){
            int diff=abs(leftsum[i]-rightsum[i]);
            ans.push_back(diff);
        }
        return ans;
    }
};