class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        double current_sum = std::accumulate(nums.begin(), nums.begin() + k, 0.0);
        double max_sum = current_sum;

        for (int i = k; i < nums.size(); ++i) {
            current_sum += nums[i] - nums[i - k];
            max_sum = std::max(max_sum, current_sum);
        }

        return max_sum / k;
    }
};