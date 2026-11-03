class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // edge case: size = 1
        if (nums.size() == 1) return 1;

        // create a vector that store the maximum until until that number
        vector<int> dp(nums.size(), 1);

        int result = 1;

        // lets start from the second to last num
        for (int i = nums.size() - 2; i >= 0; --i) {
            int curMax = 1;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] < nums[j]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            result = max(result, dp[i]);   
        }

        return result;
    }
};
