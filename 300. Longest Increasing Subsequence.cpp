class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        //note that the shortest possible increasing sequence's length is 1!
        //dp[i]: length of longest increasing subsequence ending at i
        vector<int> dp(n, 1);
        int ans = 1;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                /*
                before nums[i], add the increasing subsequence ending at j
                */
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            // cout << dp[i] << " ";
            ans = max(ans, dp[i]);
        }
      return ans;
    }
};
