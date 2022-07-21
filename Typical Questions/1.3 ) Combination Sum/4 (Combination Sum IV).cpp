class Solution {
public:
    int cs(vector<int>& nums,int target,vector<int>& dp) {
        if(dp[target] > -1) return dp[target];
        
        int cnt = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            if(nums[i] <= target)
                cnt += cs(nums,target-nums[i],dp);
        }
        dp[target] = cnt;
        return cnt;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        dp[0] = 1;
        cs(nums,target,dp);
        return dp[target];
    }
};
