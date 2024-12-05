#include <iostream>
using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const string xmas = "XMAS";

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

    auto countXMAS = [&](int i, int j) {
        int cnt = 0;
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                if (!di && !dj) continue;

                bool ok = true;
                for (int k = 1; k < 4; k++) {
                    int ni = i + di * k, nj = j + dj * k;

                    if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                        G[ni][nj] == xmas[k]) {
                    } else {
                        ok = false;
                        break;
                    }
                }
                cnt += ok;
            }
        }
        return cnt;
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (G[i][j] == xmas[0]) {
                ans += countXMAS(i, j);
            }
        }
    }

    cout << ans << '\n';
}
