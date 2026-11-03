class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curMax = 1, curMin = 1;

        for (auto num: nums) {
            int tmp = num * curMax;
            curMax = max(max(num*curMax, num * curMin), num);
            curMin = min(min(tmp, num * curMin), num);
            
            res = max(res, curMax);
        }

        return res;
    }
};
