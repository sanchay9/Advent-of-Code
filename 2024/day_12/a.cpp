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

    vector<string> G;
    string line;
    while (getline(cin, line)) {
        G.push_back(line);
    }

    int n = static_cast<int>(G.size());
    int m = static_cast<int>(G[0].size());

    auto ok = [&](int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m;
    };

    vector<vector<int>> vis(n, vector<int>(m));

    function<pair<int, int>(int, int)> dfs = [&](int x,
                                                 int y) -> pair<int, int> {
        int area = 1, perimeter = 0;
        for (auto [dx, dy] : dirs) {
            int nx = x + dx, ny = y + dy;

            if (ok(nx, ny) && G[nx][ny] == G[x][y]) {
                if (!vis[nx][ny]) {
                    vis[nx][ny] = true;
                    auto [ar, peri] = dfs(nx, ny);
                    area += ar;
                    perimeter += peri;
                }
            } else {
                ++perimeter;
            }
        }
        return {area, perimeter};
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) {
                vis[i][j] = true;

                auto [area, perimeter] = dfs(i, j);
                ans += area * perimeter;
            }
        }
    }
    cout << ans << '\n';
}
