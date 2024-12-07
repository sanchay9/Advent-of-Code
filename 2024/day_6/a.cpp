#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    map<char, char> nextarrow = {
        {'<', '^'},
        {'^', '>'},
        {'>', 'v'},
        {'v', '<'},
    };
    map<char, pair<int, int>> arrows = {
        {'<', {0, -1}},
        {'^', {-1, 0}},
        {'>', {0, 1} },
        {'v', {1, 0} },
    };

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

    int starti = -1, startj = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arrows.find(G[i][j]) != arrows.end()) {
                starti = i;
                startj = j;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({starti, startj});
    while (!q.empty()) {
        auto [curi, curj] = q.front();
        q.pop();

        int ni = curi + arrows[G[curi][curj]].first;
        int nj = curj + arrows[G[curi][curj]].second;

        if (ni < 0 || nj < 0 || ni >= n || nj >= m) {
            break;
        }

        if (G[ni][nj] == '#') {
            G[curi][curj] = nextarrow[G[curi][curj]];
            q.push({curi, curj});
        } else {
            G[ni][nj] = G[curi][curj];
            q.push({ni, nj});
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arrows.find(G[i][j]) != arrows.end()) {
                ++ans;
            }
        }
    }

    cout << ans << '\n';
}