#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int scores[2] = {0, 0};
        int currentPlayer = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i % 6 == 5) currentPlayer ^= 1;
            if (nums[i] % 2 == 1) currentPlayer ^= 1;
            scores[currentPlayer] += nums[i];
        }
        if (scores[0] > scores[1]) {
            return scores[0] - scores[1];
        } else {
            return scores[1] - scores[0];
        }
        return 0;
    }
};

int main() {
    std::vector<int> nums = {2,4,2,1,2,1};
    Solution sol;
    int ans = sol.scoreDifference(nums);
    std::cout << ans << std::endl;
    return 0;
}