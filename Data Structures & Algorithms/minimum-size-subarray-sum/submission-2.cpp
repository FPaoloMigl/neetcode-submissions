class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;

        int j = 0;
        if (nums[j] >= target) res = 1;
        int sum = nums[j];

        for (int i = 1; i < nums.size(); i++) {
            sum = sum + nums[i];

            while (sum >= target) {
                res = min(res, (i - j + 1));
                sum-=nums[j];
                j++;
            } 
        }
        return (res==INT_MAX) ? 0 : res;
    }
};