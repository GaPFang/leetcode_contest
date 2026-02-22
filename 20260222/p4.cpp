#include <bits/stdc++.h>

using namespace std;

array<int, 3> fractorize(long long n) {
    array<int, 3> factors = {0, 0, 0};
    if (n <= 0) return {-1, 0, 0}; 
    while (n % 2 == 0) {
        factors[0]++;
        n /= 2;
    }
    while (n % 3 == 0) {
        factors[1]++;
        n /= 3;
    }
    while (n % 5 == 0) {
        factors[2]++;
        n /= 5;
    }
    if (n > 1) {
        factors[0] = -1;
    }
    return factors;
}

class Solution {
public:
    array<int, 3> k_factors;
    map<pair<int, array<int, 3>>, int> memo;
    vector<array<int, 3>> nums_factors;

    int dp(int idx, int e2, int e3, int e5) {
        if (idx == nums_factors.size()) {
            return (e2 == k_factors[0] && e3 == k_factors[1] && e5 == k_factors[2]) ? 1 : 0;
        }

        array<int, 3> num_factors = {e2, e3, e5};
        if (memo.count({idx, num_factors})) {
            return memo[{idx, num_factors}];
        }

        auto& f = nums_factors[idx];
        int res = dp(idx + 1, e2 + f[0], e3 + f[1], e5 + f[2]);
        res += dp(idx + 1, e2 - f[0], e3 - f[1], e5 - f[2]);
        res += dp(idx + 1, e2, e3, e5);

        memo[{idx, num_factors}] = res;
        return res;
    }

    int countSequences(vector<int>& nums, long long k) {
        k_factors = fractorize(k);
        if (k_factors[0] == -1) {
            return 0;
        }
        for (int x : nums) {
            nums_factors.push_back(fractorize(x));
        }

        return dp(0, 0, 0, 0);
    }
};

int main() {
    std::vector<int> nums = {4, 6, 3};
    long long k = 2;
    Solution sol;
    int ans = sol.countSequences(nums, k);
    std::cout << ans << std::endl;
    return 0;
}