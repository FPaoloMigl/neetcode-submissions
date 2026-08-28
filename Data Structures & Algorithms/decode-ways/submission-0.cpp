class Solution {
public:
    int numDecodings(string s) {
        int prev1 = 1;
        int prev2 = 1;

        if (s[0] == '0') return 0;

        for (int i = 1; i < s.size(); i++) {
            int curr = 0;

            // 1 digit
            if (s[i] != '0') {
                curr+=prev1;
            }

            // 2 digits
            int num = (s[i-1] - '0') * 10 + (s[i] - '0');
            if (num >= 10 && num <= 26) {
                curr+=prev2;
            }

            if (curr == 0) return 0;

            prev2=prev1;
            prev1=curr;
        }

        return prev1;
    }
};
