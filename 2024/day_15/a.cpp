#include <bits/stdc++.h>
using namespace std;
#define int int64_t

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> G;

    string line;
    while (getline(cin, line)) {
        if (line.empty()) {
            break;
        }

        G.push_back(line);
    }

    int n = static_cast<int>(G.size());
    int m = static_cast<int>(G[0].size());

    map<char, pair<int, int>> mp{
        {'<', {0, -1}},
        {'^', {-1, 0}},
        {'>', {0, 1} },
        {'v', {1, 0} },
    };

    auto ok = [&](int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m;
    };

    auto update = [&](int &curi, int &curj, char move) {
        char last = '@';

        auto [di, dj] = mp[move];

        int nexti = curi + di;
        int nextj = curj + dj;

        for (int i = nexti, j = nextj; ok(i, j); i += di, j += dj) {
            if (G[i][j] == '.') {
                G[i][j] = last;
                break;
            }
            if (G[i][j] == 'O') {
                last = 'O';
            } else if (G[i][j] == '#') {
                return;
            }
        }

        G[nexti][nextj] = '@';
        G[curi][curj] = '.';
        curi = nexti;
        curj = nextj;
    };

    int curi, curj;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (G[i][j] == '@') {
                curi = i;
                curj = j;
            }
        }
    }

    while (getline(cin, line)) {
        for (auto move : line) {
            update(curi, curj, move);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (G[i][j] == 'O') {
                ans += 100 * i + j;
            }
        }
    }
    cout << ans << '\n';
}
