class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0; 
        int r = height.size() - 1;
        int global_max = 0;

        while (l < r) {
            int current_area = (r - l) * std::min(height[l], height[r]);
            global_max = std::max(global_max, current_area);

            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }

        return global_max;
    }
};