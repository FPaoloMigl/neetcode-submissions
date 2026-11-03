class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
       vector<bool> dp(s.size() + 1, false);

       // the last value is always true because it's the end
       dp[s.size()] = true;

       for (int i = s.size() - 1; i >= 0; --i) {
            for (const auto& word: wordDict) {
                // check if 
                // - the string s has enough character to compare with the word in the dict
                // - check if the word exists in the string s
                if ((i + word.size()) <= s.size() && s.substr(i, word.size()) == word) {
                    // we set the value inside dp at that index equal to i + word.size() 
                    // because this tells us until that point we found all the words
                    dp[i] = dp[i + word.size()];
                }

                // if we found the word we don't need to iterate over all the other words
                if (dp[i]) break;
            }
       }

       return dp[0];
    }
};
