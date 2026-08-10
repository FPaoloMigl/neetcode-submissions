class Solution {
public:
    bool isPalindrome(string s) {
        // remove the spaces
        std::erase(s, ' ');
        std::erase_if(s, [](unsigned char c) {
            return !std::isalnum(c);
        });
 
        int i = 0; 
        int j = s.size() - 1;

        while(i <= j) {
            if (std::tolower(s[i]) != std::tolower(s[j])) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};
