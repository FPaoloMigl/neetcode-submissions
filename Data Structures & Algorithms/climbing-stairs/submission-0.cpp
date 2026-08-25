class Solution {
public:
    unordered_map<int, int> memo;
    
    int climbStairs(int n) {
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }

        if (n == 1) {
            memo[n] = 1;
            return memo[n];
        }

        if (n == 2) {
            memo[n] = 2;
            return memo[n];
        }

        // use -1 branch
        memo[n] = climbStairs(n - 1) + climbStairs(n-2);
        return memo[n];

    }
};
