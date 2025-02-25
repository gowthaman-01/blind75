class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        std::array<int, 26> counter{};

        for (char c: s) {
            counter[c - 'a']++;
        }

        for (char c: t) {
            if (!counter[c - 'a'] || --counter[c - 'a'] < 0) {
                return false;
            }            
        }

        return true;
    }
};