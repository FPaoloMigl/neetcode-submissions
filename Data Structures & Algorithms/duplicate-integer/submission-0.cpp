class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> lookup;

        for (auto& elem : nums) {
            if (lookup.find(elem) != lookup.end()){
                return true;
            } else {
                lookup[elem] = 1;
            }
        }

        return false;
    }
};