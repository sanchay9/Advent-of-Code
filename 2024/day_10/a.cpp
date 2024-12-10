#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const vector<pair<int, int>> dirs{
    {-1, 0 },
    {0,  1 },
    {1,  0 },
    {0,  -1}
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> G;
    string line;
    while (getline(cin, line)) {
        G.emplace_back();
        for (auto x : line) {
            G.back().push_back(x - '0');
        }
    }

    int n = static_cast<int>(G.size());
    int m = static_cast<int>(G[0].size());

    auto score = [&](int x, int y) {
        queue<pair<int, int>> q;
        q.emplace(x, y);

        set<pair<int, int>> ends;
        while (!q.empty()) {
            auto [curx, cury] = q.front();
            q.pop();

            if (G[curx][cury] == 9) {
                ends.insert({curx, cury});
            }

            for (auto [dx, dy] : dirs) {
                int nx = curx + dx;
                int ny = cury + dy;

                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                    G[nx][ny] == G[curx][cury] + 1) {
                    q.emplace(nx, ny);
                }
            }
        }
        return static_cast<int>(ends.size());
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (G[i][j] == 0) {
                ans += score(i, j);
            }
        }
    }

    cout << ans << '\n';
}
