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
        int area = 1, corners = 0;
        for (int i = 0; i < 4; i++) {
            int nx1 = x + dirs[i].first, ny1 = y + dirs[i].second;
            int nx2 = x + dirs[(i + 1) % 4].first,
                ny2 = y + dirs[(i + 1) % 4].second;

            int nxdiagonal = x + dirs[i].first + dirs[(i + 1) % 4].first,
                nydiagonal = y + dirs[i].second + dirs[(i + 1) % 4].second;

            if (((!ok(nx1, ny1) || G[nx1][ny1] != G[x][y]) &&
                 (!ok(nx2, ny2) || G[nx2][ny2] != G[x][y])) ||
                (ok(nx1, ny1) && G[nx1][ny1] == G[x][y] && ok(nx2, ny2) &&
                 G[nx2][ny2] == G[x][y] &&
                 G[nxdiagonal][nydiagonal] != G[x][y])) {
                ++corners;
            }
        }

        for (auto [dx, dy] : dirs) {
            int nx = x + dx, ny = y + dy;

            if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                G[nx][ny] == G[x][y]) {
                if (!vis[nx][ny]) {
                    vis[nx][ny] = true;
                    auto [ar, cor] = dfs(nx, ny);
                    area += ar;
                    corners += cor;
                }
            }
        }

        return {area, corners};
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) {
                vis[i][j] = true;

                auto [area, corners] = dfs(i, j);
                ans += area * corners;
            }
        }
    }
    cout << ans << '\n';
}
