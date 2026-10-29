class Solution {
public:
    int rob(vector<int>& nums) {
        // To do rob 2 we need to do first rob 1 
        return max(nums[0],
               max(rob1(vector<int>(nums.begin() + 1, nums.end())), rob1(vector<int>(nums.begin(), nums.end() - 1))));
    }

private: 

    int rob1(vector<int> nums) {
        // here we need just two variable so we can solve rob 1 with space optimized
        int rob1 = 0; // best up to house i - 2
        int rob2 = 0; // best up to house i - 1

        for (auto num : nums) {
            int tmp = max(rob1 + num, rob2);
            rob1 = rob2;
            rob2 = tmp;
        }
        return rob2;
    }
};
