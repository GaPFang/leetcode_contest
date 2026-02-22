#include <bits/stdc++.h>

using namespace std;

int factorial_arr[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

class Solution {
public:
    bool isDigitorialPermutation(int n) {
        string s_n = to_string(n);
        int sum = 0;
        for (char c : s_n) {
            sum += factorial_arr[c - '0'];
        }
        string s_sum = to_string(sum);
        int count_n[10] = {0};
        int count_sum[10] = {0};
        for (char c : s_n) {
            count_n[c - '0']++;
        }
        for (char c : s_sum) {
            count_sum[c - '0']++;
        }
        for (int i = 0; i < 10; ++i) {
            if (count_n[i] != count_sum[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int n = 10;
    Solution sol;
    int ans = sol.isDigitorialPermutation(n);
    std::cout << ans << std::endl;
    return 0;
}