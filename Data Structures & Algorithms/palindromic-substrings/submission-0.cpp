class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;

        // edge case size = 1
        if (s.size() == 1) return 1;

        // lets start with odd length palindromes
        for (int i = 0; i < s.size(); i++) {
            int l = i, r = i;

            while (s[l] == s[r]) {
                res++;

                if (l == 0 || r == s.size() - 1) {
                    break;
                } else{
                    l--;
                    r++;
                }
            }
        }

        // even length palindrome
        for (int i = 0; i < s.size(); ++i) {
            int l = i;
            int r = i + 1;

            // at least two 
            while (s[l] == s[r]) {
                res++;
                if (l == 0 || r == s.size() - 1) {
                    break;
                } else {
                    l--;
                    r++;
                }
            }
        }

        return res;
    }
};
