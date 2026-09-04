class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> numbers(nums.begin(), nums.end());

        for (auto& num : nums) {
            int max = 1;
            if (numbers.find(num-1) == numbers.end()) { // start of the sequence
                while (numbers.find(++num) != numbers.end()) {
                    max++;
                }
            }

            res = std::max(max, res);
        }

        return res;
    }
};
