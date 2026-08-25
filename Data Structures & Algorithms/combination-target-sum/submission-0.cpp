class Solution {
public:
    vector<vector<int>> res;
    void backtracking(int i, vector<int>& nums, int target, vector<int> path, int sum) { 
        // Question 1 -- Reach the goal
        if (sum == target) {
            res.push_back(path);
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            if (sum + nums[i] > target) return;

            path.push_back(nums[j]);
            backtracking(j, nums, target, path, sum + nums[j]);
            path.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        //important to sort
        sort(nums.begin(), nums.end());
        backtracking(0, nums, target, {} , 0);
        
        return res;
    }


};
