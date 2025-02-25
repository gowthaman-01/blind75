class Solution {
private:
    std::string get_key(const std::string& word) {
        std::array<int, 26> char_array{};
        for (char c: word) {
            char_array[c - 'a']++;
        }

        std::string key = "";
        for (int n: char_array) {
            key += std::to_string(n) + "/";
        }

        return key;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> anagram_map;

        for (auto &s: strs) {
            anagram_map[get_key(s)].push_back(s);
        }

        std::vector<std::vector<std::string>> res;
        res.reserve(anagram_map.size());

        for (auto &[key, anagrams]: anagram_map) {
            res.push_back(std::move(anagrams));
        }

        return res;
    }
};