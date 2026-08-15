class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        // we are going to use sliding window
        int l = 0; // this is gonna be the start of the window and we will move it to move the window
        int window = 0; // this will be the value of the current window
        int satisfied = 0; // we need this because at the normal satisfied we need to add the window with the max value
        int maxWindow = 0; // this is gonna use to keep track of the max window
        for (int r = 0; r < customers.size(); r++) {
            if (grumpy[r] == 1) {
                window += customers[r]; // if it's add to the window is not added to satisfied
            } else {
                satisfied += customers[r];
            }

            //check if the window is too big
            if (r - l + 1 > minutes) {
                //remove from the window the value at the left pointer 
                // only if grumpy
                if (grumpy[l ] == 1) {
                    window -= customers[l];
                }
                // increment the pointer
                l++;
            }

            maxWindow = max(window, maxWindow);
        }

        return satisfied + maxWindow;
    }
};