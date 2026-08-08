class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> lookup;

        for (int i = 0; i < nums.size(); i++) {
            lookup[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); ++i) {
            int comple = target - nums[i];
            if (lookup.find(comple) != lookup.end() && lookup[comple] != i) {
                return {i, lookup[comple]};
            }
        }

        return {};
    }
};
