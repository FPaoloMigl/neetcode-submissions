class Solution {
public:
    string longestPalindrome(string s) {
        // same concept as number palindromic substrings
        // start at the letter and expand starting from that
        string res = "";
        int longest = 1;
        int idx_r = 0, idx_l = 0;

        // edge case size == 1
        if (s.size() == 1) return s.substr(0, 1);

        for (int i = 0; i < s.size(); ++i) {
            int l = i, r = i;

            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > longest) {
                    longest = r - l;
                    idx_r = r;
                    idx_l = l;
                }
                r++;
                l--;
            }

            // in case of odd length
            l = i;
            r = i + 1;

            while (l >= 0 && r < s.size() && s[r] == s[l]) {
                if (r - l + 1 > longest) { 
                    longest = r - l;
                    idx_r = r;
                    idx_l = l;
                }

                r++;
                l--;
            }

            res = s.substr(idx_l, idx_r - idx_l + 1);
        }
        return res;
    }
};
