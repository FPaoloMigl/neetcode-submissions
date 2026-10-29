class Solution {
public:
    int rob(vector<int>& nums) {
        // To use an approach bottom up we need an array to store the result
        // of the max until i house
        
        // Edge case 
        if (nums.size() == 1) return nums[0];

        // create the vector to store results
        vector<int> dp(nums.size());

        // the first house the value is gonna be that house
        dp[0] = nums[0];
        // for the second house we are gonna find the max between the house before and this house
        dp[1] = max(dp[0], nums[1]);

        // we set the first two house because after that we are gonna use a loop
        // otherwise we risk to go overflow and we would need to handle that
        // in this case it's easier
        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        return dp[nums.size() - 1];
    }
};
