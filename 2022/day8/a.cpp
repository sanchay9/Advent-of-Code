#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    string s;

    vector<vector<int> > G;

    while (cin >> s) {
        vector<int> tmp;

        for (auto x : s) {
            tmp.push_back(x - '0');
        }

        G.push_back(tmp);
    }

    int n = G.size(), m = G[0].size();

    vector<vector<bool> > ans(n, vector<bool> (m));

    for (int i = 0; i < n; i++) {
        int mx = G[i][0];
        ans[i][0] = 1;

        for (int j = 1; j < m; j++) {
            if (G[i][j] > mx) {
                ans[i][j] = 1;
                mx = G[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int mx = G[i][m - 1];
        ans[i][m - 1] = 1;

        for (int j = m - 2; j >= 0; j--) {
            if (G[i][j] > mx) {
                ans[i][j] = 1;
                mx = G[i][j];
            }
        }
    }

    for (int j = 0; j < m; j++) {
        int mx = G[0][j];
        ans[0][j] = 1;

        for (int i = 1; i < n; i++) {
            if (G[i][j] > mx) {
                ans[i][j] = 1;
                mx = G[i][j];
            }
        }
    }

    for (int j = 0; j < m; j++) {
        int mx = G[n - 1][j];
        ans[n - 1][j] = 1;

        for (int i = n - 2; i >= 0; i--) {
            if (G[i][j] > mx) {
                ans[i][j] = 1;
                mx = G[i][j];
            }
        }
    }

    int cnt = 0;
    for (auto x : ans) {
        for (auto y : x) {
            cnt += y == 1;
        }
    }

    cout << cnt << '\n';
}
