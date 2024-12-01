#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> G;
    string line;
    while (getline(cin, line)) {
        G.push_back(line);
    }

    vector<pair<int, int>> dirs{
        {-1, 0 },
        {0,  1 },
        {1,  0 },
        {0,  -1}
    };

    int loop_size = 0;
    function<void(int, int, int, int)> dfs =
        [&](int i, int j, int prei, int prej) -> void {
        ++loop_size;

        if (G[i][j] == 'S') return;

        if (G[i][j] == '|') {
            if (i == prei + 1) {
                dfs(i + 1, j, i, j);
            } else {
                dfs(i - 1, j, i, j);
            }
        }
        if (G[i][j] == '-') {
            if (j == prej + 1) {
                dfs(i, j + 1, i, j);
            } else {
                dfs(i, j - 1, i, j);
            }
        }
        if (G[i][j] == 'F') {
            if (prei == i) {
                dfs(i + 1, j, i, j);
            } else {
                dfs(i, j + 1, i, j);
            }
        }
        if (G[i][j] == '7') {
            if (prei == i) {
                dfs(i + 1, j, i, j);
            } else {
                dfs(i, j - 1, i, j);
            }
        }
        if (G[i][j] == 'L') {
            if (prei == i) {
                dfs(i - 1, j, i, j);
            } else {
                dfs(i, j + 1, i, j);
            }
        }
        if (G[i][j] == 'J') {
            if (prei == i) {
                dfs(i - 1, j, i, j);
            } else {
                dfs(i, j - 1, i, j);
            }
        }
    };

    int n = static_cast<int>(G.size()), m = static_cast<int>(G[0].size());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (G[i][j] == 'S') {
                if (i - 1 >= 0 && (G[i - 1][j] == '|' || G[i - 1][j] == '7' ||
                                   G[i - 1][j] == 'F')) {
                    dfs(i - 1, j, i, j);
                } else if (i + 1 < n &&
                           (G[i + 1][j] == '|' || G[i + 1][j] == 'L' ||
                            G[i + 1][j] == 'J')) {
                    dfs(i + 1, j, i, j);
                } else if (j - 1 >= 0 &&
                           (G[i][j - 1] == '-' || G[i][j - 1] == 'F' ||
                            G[i - 1][j] == 'L')) {
                    dfs(i, j - 1, i, j);
                } else {
                    dfs(i, j + 1, i, j);
                }
            }
        }
    }

    cout << (loop_size + 1) / 2 << '\n';
}
