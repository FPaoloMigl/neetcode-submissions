class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res = nums;
        for (auto& elem : nums) {
            res.push_back(elem);
        }

        return res;
    }
};