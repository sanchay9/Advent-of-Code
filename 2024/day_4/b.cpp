#include <iostream>
#include <map>
using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const string xmas = "XMAS";

    vector<vector<char>> G;
    string line;
    while (getline(cin, line)) {
        G.emplace_back();
        for (auto x : line) {
            G.back().push_back(x);
        }
    }

    int n = static_cast<int>(G.size());
    int m = static_cast<int>(G[0].size());

    auto countMAS = [&](int x, int y) {
        if (G[x + 1][y + 1] == G[x - 1][y - 1]) return false;

        map<char, int> mp;
        ++mp[G[x + 1][y + 1]];
        ++mp[G[x - 1][y + 1]];
        ++mp[G[x + 1][y - 1]];
        ++mp[G[x - 1][y - 1]];

        return mp['M'] == 2 && mp['S'] == 2;
    };

    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (G[i][j] == 'A') {
                if (countMAS(i, j)) {
                    ++ans;
                }
            }
        }
    }

    cout << ans << '\n';
}
