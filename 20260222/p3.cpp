#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string maximumXor(string s, string t) {
        int ones_in_t = count(t.begin(), t.end(), '1');
        vector<int> zero_positions;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '0' && ones_in_t > 0) {
                s[i] = '1';
                --ones_in_t;
                zero_positions.push_back(i);
            }
        }
        for (int i = s.length() - 1; i >= 0 && ones_in_t > 0; --i) {
            if (s[i] == '1' && find(zero_positions.begin(), zero_positions.end(), i) == zero_positions.end()) {
                s[i] = '0';
                --ones_in_t;
            }
        }
        return s;
    }
};

int main() {
    string s = "0110";
    string t = "1110";
    Solution sol;
    string ans = sol.maximumXor(s, t);
    std::cout << ans << std::endl;
    return 0;
}