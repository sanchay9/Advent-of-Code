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

    auto isDigit = [&](int i, int j) {
        return G[i][j] >= '0' && G[i][j] <= '9';
    };

    const vector<pair<int, int>> dirs{
        {-1, 0 },
        {-1, 1 },
        {0,  1 },
        {1,  1 },
        {1,  0 },
        {1,  -1},
        {0,  -1},
        {-1, -1},
    };

    int n = static_cast<int>(G.size()), m = static_cast<int>(G[0].size());
    auto num = [&](int i, int j) {
        string tmp;
        while (j < m && isDigit(i, j)) {
            tmp.push_back(G[i][j++]);
        }
        return stoll(tmp);
    };

    map<pair<int, int>, vector<pair<int, int>>> stars;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isDigit(i, j)) {
                int si = i, sj = j;
                bool found = false;
                while (j < m && isDigit(i, j)) {
                    if (!found) {
                        for (auto [di, dj] : dirs) {
                            int ni = i + di, nj = j + dj;
                            if (ni >= 0 && nj >= 0 && ni < n && nj < m &&
                                !isDigit(ni, nj) && G[ni][nj] != '.') {
                                if (G[ni][nj] == '*') {
                                    stars[{ni, nj}].emplace_back(si, sj);
                                    found = true;
                                    break;
                                }
                            }
                        }
                    }
                    ++j;
                }
            }
        }
    }

    int ans = 0;
    for (auto [k, v] : stars) {
        if (v.size() == 2) {
            ans += num(v[0].first, v[0].second) * num(v[1].first, v[1].second);
        }
    }
    cout << ans << '\n';
}
