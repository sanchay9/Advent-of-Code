#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

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

    map<char, vector<pair<int, int>>> antennas;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isalpha(G[i][j]) || isdigit(G[i][j])) {
                antennas[G[i][j]].emplace_back(i, j);
            }
        }
    }

    auto isValidPoint = [&](int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m;
    };

    set<pair<int, int>> ans;
    for (auto [antenna, locations] : antennas) {
        int len = static_cast<int>(locations.size());

        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                int xdiff = locations[j].first - locations[i].first;
                int ydiff = locations[j].second - locations[i].second;

                for (int anx = locations[i].first, any = locations[i].second;
                     isValidPoint(anx, any);
                     anx -= xdiff, any -= ydiff) {
                    ans.insert({anx, any});
                }

                for (int anx = locations[j].first, any = locations[j].second;
                     isValidPoint(anx, any);
                     anx += xdiff, any += ydiff) {
                    ans.insert({anx, any});
                }
            }
        }
    }

    cout << ans.size() << '\n';
}
