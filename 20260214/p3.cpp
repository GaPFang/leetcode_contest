#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        array<vector<long long>, 2> dp;
        dp[0].reserve(nums.size());
        dp[1].reserve(nums.size());
        dp[0].push_back(nums[0]);
        dp[1].push_back(0);
        for (size_t i = 1; i < nums.size(); i++) {
            if (colors[i] == colors[i - 1]) {
                dp[0].push_back(dp[1][i - 1] + nums[i]);
                dp[1].push_back(dp[0][i - 1]);
            } else {
                dp[0].push_back(max(dp[0][i - 1], dp[1][i - 1]) + nums[i]);
                dp[1].push_back(max(dp[0][i - 1], dp[1][i - 1]));
            }
        }
        return max(dp[0][nums.size() - 1], dp[1][nums.size() - 1]);
    }
};

int main() {
    std::vector<int> nums = {3,1,2,4};
    vector<int> colors = {1,2,1,1};
    Solution sol;
    long long ans = sol.rob(nums, colors);
    std::cout << ans << std::endl;
    return 0;
}