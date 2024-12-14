#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int n = 101, m = 103;

    auto score = [](vector<vector<int>> &G) {
        int mxi = 0, mxj = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                cnt += G[i][j];
            }
            mxi = max(mxi, cnt);
        }
        for (int j = 0; j < m; j++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += G[i][j];
            }
            mxj = max(mxj, cnt);
        }
        return mxi * mxj;
    };

    vector<int> sxs, sys, vxs, vys;
    string p, v;
    while (cin >> p >> v) {
        int idxequals = static_cast<int>(p.find('='));
        int idxcomma = static_cast<int>(p.find(','));
        int sx = stoll(p.substr(idxequals + 1, idxcomma - idxequals - 1));
        int sy = stoll(p.substr(idxcomma + 1));

        idxequals = static_cast<int>(v.find('='));
        idxcomma = static_cast<int>(v.find(','));
        int vx = stoll(v.substr(idxequals + 1, idxcomma - idxequals - 1));
        int vy = stoll(v.substr(idxcomma + 1));

        sxs.push_back(sx);
        sys.push_back(sy);
        vxs.push_back(vx);
        vys.push_back(vy);
    }

    int num_robots = static_cast<int>(sxs.size());

    int ans = 0, mxscore = 0;
    for (int t = 0; t < n * m; t++) {
        vector<vector<int>> G(n, vector<int>(m));
        for (int i = 0; i < num_robots; i++) {
            int px = (sxs[i] + (vxs[i] + n) * t) % n;
            int py = (sys[i] + (vys[i] + m) * t) % m;

            G[px][py] = 1;
        }

        int curscore = score(G);
        if (curscore > mxscore) {
            mxscore = curscore;
            ans = t;
        }
    }

    vector<vector<int>> G(n, vector<int>(m));
    for (int i = 0; i < num_robots; i++) {
        int px = (sxs[i] + (vxs[i] + n) * ans) % n;
        int py = (sys[i] + (vys[i] + m) * ans) % m;

        G[px][py] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (G[i][j] == 0) {
                cerr << '.';
            } else {
                cerr << G[i][j];
            }
        }
        cerr << '\n';
    }

    cout << ans << '\n';
}
