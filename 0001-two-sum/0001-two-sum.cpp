class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> num_to_index;

        for (int i = 0; i < nums.size(); i++) {
            if (num_to_index.count(target - nums[i])) {
                return {i, num_to_index[target - nums[i]]};
            } else {
                num_to_index[nums[i]] = i;
            }
        }

        return {};
    }
};