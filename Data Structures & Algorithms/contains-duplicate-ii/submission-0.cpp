class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lookup;

        for (int i = 0; i < nums.size(); i++) {
            if (lookup.find(nums[i]) == lookup.end()) {
                lookup[nums[i]] = i;
            }else {
                if (i - lookup[nums[i]] <= k) {
                    return true;
                } else {
                    lookup[nums[i]] = i;
                }
            }
        }

        return false;
    }
};