class Solution {
public:
    int lengthOfLongestSubstring(string s) {

       // algorithm:
       // increase window as long as different letters
       // update counter every time
       // if letter encountered decrease window until the window is clean

        int res = 0;
        int l = 0;
        set<char> window;

        for (int r = 0; r < s.size(); r++) {
            while (window.find(s[r]) != window.end() && l < r) {
                window.erase(s[l]);
                l++;
                
            }
            if (window.find(s[r]) == window.end()) {
                window.emplace(s[r]);
            }
            int size = window.size();
            res = max(res, size); 
        }

        return res;

    }
};
