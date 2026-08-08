class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> lookup;

        for (int i = 0; i < s.size(); i++) {
            if (lookup.find(s[i]) != lookup.end()){
                // exists
                lookup[s[i]] += 1;
            } else {
                lookup[s[i]] = 1;
            }
        }

        for (int i = 0; i < t.size(); i++) {
            if(lookup.find(t[i]) == lookup.end()) {
                return false;
            } else {
                lookup[t[i]]--;
            }

            if (lookup[t[i]] == 0) {
                lookup.erase(t[i]);
            } 
        }

        return lookup.empty() ? true : false;
    }
};
