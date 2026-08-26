class Solution {
public:
    unordered_map<int, int> memo;

    int dp(vector<int>& nums, int n) {
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }

        if (n == nums.size() - 2) {
            memo[n] = nums[n];
        }

        for (int i = n + 2; i<nums.size(); i++) {
            memo[n] = max(memo[n], nums[n] + dp(nums, i));
        }

        return memo[n];
    }
    int rob(vector<int>& nums) {
        auto size = nums.size();
        memo[size - 1] = nums[size-1];
        int sum = memo[size-1];
        // memo[size-2] = nums[size-2]; // doesn't work if size = 1
    
        for (int i = size - 2; i >= 0 ; --i) {
            cout << "HERE" << endl;
            memo[i] = dp(nums, i);
            sum = max(sum, memo[i]);
        }
        
        return sum;
    }
};
