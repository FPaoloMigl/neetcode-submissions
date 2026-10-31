class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // for this solution i'm gonna use a bottom-up approach, in this case
        // we need to find the least subproblem which is amount = 0 and count how many
        // coins do we need. So we need a VECTOR that store the amount of coins 
        // for each amount until actual amount 
        vector<int> dp (amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i){
            for (auto coin: coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};
