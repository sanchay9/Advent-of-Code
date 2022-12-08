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

    int ans = 0;

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            int k, score = 1;

            for (k = i - 1; k >= 1; k--) {
                if (G[k][j] >= G[i][j]) break;
            }
            score *= (i - k);

            for (k = i + 1; k < n - 1; k++) {
                if (G[k][j] >= G[i][j]) break;
            }
            score *= (k - i);

            for (k = j - 1; k > 0; k--) {
                if (G[i][k] >= G[i][j]) break;
            }
            score *= (j - k);

            for (k = j + 1; k < m - 1; k++) {
                if (G[i][k] >= G[i][j]) break;
            }
            score *= (k - j);

            ans = max(ans, score);
        }
    }

    cout << ans << '\n';
}
