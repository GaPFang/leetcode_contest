#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        map<string, int> dict;
        int ans = 0;
        for (const auto& s : words) {
            if (s.length() >= k) {
                std::string prefix = s.substr(0, k);
                dict[prefix]++;
            }
        }
        for (auto const& [prefix, count] : dict) {
            if (count >= 2) {
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    std::vector<string> nums = {"bat","dog","dog","doggy","bat", "cat", "catt"};
    int weight = 3;
    Solution sol;
    int ans = sol.prefixConnected(nums, weight);
    std::cout << ans << std::endl;
    return 0;
} 