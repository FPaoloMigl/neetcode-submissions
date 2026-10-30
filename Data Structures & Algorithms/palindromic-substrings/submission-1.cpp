class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;

        // edge case size = 1
        if (s.size() == 1) return 1;

        // lets start with odd length palindromes
        for (int i = 0; i < s.size(); i++) {
            int l = i, r = i;

            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                res++;
                l--;
                r++;
            }

            // odd length
            l = i;
            r = i + 1;

            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                res++;
                l--;
                r++;
            }
        }

        return res;
    }
};
