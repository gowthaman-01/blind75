class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        for (int num: nums) {
            freq[num]++;
        }

        std::vector<std::vector<int>> bucket(nums.size() + 1);
        for (auto &[num, count]: freq) {
            bucket[count].push_back(num);
        }

        std::vector<int> res;
        res.reserve(k);
        for (int i = nums.size(); i >= 0; i--) {
            for (auto num: bucket[i]) {
                res.push_back(num);
                k--;
                if (k == 0) {
                    return res;
                }
            }
        }
        
        return res;
    }

};