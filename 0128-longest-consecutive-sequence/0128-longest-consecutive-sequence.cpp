class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;
        
        for (int num: s) {
            if (s.count(num - 1)) {
                continue;
            }

            int count = 0; int cur = num;
            while (s.count(cur)) {
                count++;
                cur++;
            }
            longest = std::max(longest, count);
        }

        return longest;
    }
};