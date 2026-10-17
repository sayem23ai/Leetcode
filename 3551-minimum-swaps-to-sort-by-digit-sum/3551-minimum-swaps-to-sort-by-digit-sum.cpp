class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++){
            int x=nums[i];
            int sum=0;
            while(x>0){
                sum+=x%10;
                x=x/10;
            }
            arr.push_back({sum,nums[i]});
        }
        sort(arr.begin(),arr.end());
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        int count=0;
        for(int i=0;i<n;i++){
            while(nums[i]!=arr[i].second){
                int j=mp[arr[i].second];
                mp[nums[i]]=j;
                mp[nums[j]]=i;
                swap(nums[i],nums[j]);
                count++;
            }
        }
        return count;
    }
};