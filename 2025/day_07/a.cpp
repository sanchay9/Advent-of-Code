#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    map<int64_t, int64_t> beams;

    string line;
    cin >> line;
    for (int i = 0; i < static_cast<int>(line.size()); i++) {
        if (line[i] == 'S') {
            ++beams[i];
        }
    }

    int64_t ans = 0;
    while (getline(cin, line)) {
        int n = static_cast<int>(line.size());

        for (int i = 0; i < n; i++) {
            if (line[i] == '^' && beams.contains(i)) {
                if (i + 1 < n) {
                    ++beams[i + 1];
                }
                if (i - 1 >= 0) {
                    ++beams[i - 1];
                }
                beams.erase(i);

                ++ans;
            }
        }
    }
    cout << ans << '\n';
}
