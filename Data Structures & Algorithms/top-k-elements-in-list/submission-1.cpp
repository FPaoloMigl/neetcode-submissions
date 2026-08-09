class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> bucket(nums.size() + 1); // because we start from 1;
        unordered_map<int, int> counts;
        vector<int> result;
        
        for (auto& elem : nums) {
            counts[elem] += 1;
        }

        for (auto& elem : counts) {
            bucket[elem.second].push_back(elem.first);
        }

        for (int i = bucket.size() - 1; i > 0; --i) {
            for (int j = 0; j < bucket[i].size(); j++) {
                result.push_back(bucket[i][j]);
                if (result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }
};
