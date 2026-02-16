#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for (size_t i = 0; i < words.size(); i++) {
            int tot = 0;
            for (size_t j = 0; j < words[i].length(); j++) {
                tot += weights[words[i][j] - 'a'];
            }
            tot = 25 - (tot % 26);
            ans += (static_cast<char>(tot) + 'a');
        }
        return ans;
    }
};

int main() {
    std::vector<string> nums = {"abcd","def","xyz"};
    vector<int> weights = {5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2};
    Solution sol;
    string ans = sol.mapWordWeights(nums, weights);
    std::cout << ans << std::endl;
    return 0;
} 