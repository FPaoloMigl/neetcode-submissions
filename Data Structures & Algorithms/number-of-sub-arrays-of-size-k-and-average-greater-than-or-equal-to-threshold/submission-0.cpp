class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int l = 0;
        int res = 0;
        int sum = 0;
        //start with the first window
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        if (sum/k >= threshold) {
            res++;
        }

        for (int i = k; i < arr.size(); i++) {
            sum -= arr[l];
            l++;
            sum += arr[i];

            if (sum /k >= threshold) {
                res++;
            }
        }

        return res;
    }
};