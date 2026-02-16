#include <bits/stdc++.h>

using namespace std;

void dfs(int node, int par, const vector<vector<int>>& adj, vector<int>& parent, vector<int>& depth) {
    parent[node] = par;
    depth[node] = (par == -1) ? 0 : depth[par] + 1;
    for (const auto &neighbor : adj[node]) {
        if (neighbor != par) {
            dfs(neighbor, node, adj, parent, depth);
        }
    }
}

class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<bool> ans;
        int root = 0;
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> depth(n, 0);
        vector<int> parent(n, -1);
        dfs(root, -1, adj, parent, depth);
        for (auto cmd : queries) {
            stringstream ss(cmd);
            string type;
            ss >> type;
            if (type == "update") {
                int node;
                char newChar;
                ss >> node >> newChar;
                s[node] = newChar;
            } else if (type == "query") {
                int u, v;
                ss >> u >> v;
                if (u == v) {
                    ans.push_back(true);
                    continue;
                }
                map<char, int> mp;
                if (depth[u] < depth[v]) {
                    swap(u, v);
                }
                while (depth[u] > depth[v]) {
                    mp[s[u]]++;
                    u = parent[u];
                }
                while (u != v) {
                    mp[s[u]]++;
                    mp[s[v]]++;
                    u = parent[u];
                    v = parent[v];
                }
                mp[s[u]]++;
                bool odd_flag = false;
                bool has_pushed = false;
                for (auto& [key, val] : mp) {
                    if (val % 2 != 0) {
                        if (odd_flag) {
                            ans.push_back(false);
                            has_pushed = true;
                            break;
                        }
                        odd_flag = true;
                    }
                }
                if (!has_pushed) {
                    ans.push_back(true);
                }
            }
        }
        return ans;
    }
};

int main() {
    int n = 3;
    vector<vector<int>> edges = {{0,1},{1,2}};
    string s = "jfj";
    vector<string> queries = {"query 2 1"};
    Solution sol;
    vector<bool> ans = sol.palindromePath(n, edges, s, queries);
    for (size_t i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}