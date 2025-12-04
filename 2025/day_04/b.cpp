#include <bits/stdc++.h>
using namespace std;

static vector<pair<int, int>> directions = {
    {0,  1 },
    {1,  0 },
    {0,  -1},
    {-1, 0 },
    {-1, -1},
    {-1, 1 },
    {1,  -1},
    {1,  1 }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> G;

    string line;
    while (getline(cin, line)) {
        G.push_back(line);
    }

    int n = static_cast<int>(G.size()), m = static_cast<int>(G[0].size());
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (G[i][j] == '.') {
                continue;
            }

            int cnt = 0;
            for (auto [di, dj] : directions) {
                int ni = i + di, nj = j + dj;
                if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                    G[ni][nj] == '@') {
                    ++cnt;
                }
            }
            if (cnt < 4) {
                ++ans;
                G[i][j] = '.';
            }
        }
    }
    cout << ans << '\n';
}
