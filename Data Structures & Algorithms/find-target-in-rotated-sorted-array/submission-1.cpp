class Solution {
public:
    int search(vector<int>& nums, int target) {
        // to check if array rotate then r < l 
        int l = 0;
        int r = nums.size() - 1;

        // split the vector
        while (r >= l) {
           
            int mid = (r + l) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] >= nums[l]) {
                // ordered part
                if (target < nums[mid] && target >= nums[l]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                //rotated part
                if (target > nums[mid] && target <= nums[r]) {
                    // move to the ordered part
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1; 
    }
};
