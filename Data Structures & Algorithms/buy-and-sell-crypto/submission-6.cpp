class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int l = 0;
        int r = 1;

        // edge case
        if (prices.size() == 1) return 0;

        while (r < prices.size()) {
            int prof = 0;
            if (prices[r] < prices[l]){
                l = r;
            } else {
                prof = prices[r] - prices[l];

                profit = max(prof, profit);
            }

            r++;
        }

        return profit;

    }
};
