#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    set<pair<int64_t, int64_t>> ranges;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) break;

        size_t dash_pos = line.find('-');
        string start = line.substr(0, dash_pos);
        string end = line.substr(dash_pos + 1);
        ranges.insert({stoll(start), stoll(end)});
    }

    int64_t id, ans = 0;
    while (cin >> id) {
        for (const auto& [start, end] : ranges) {
            if (id >= start && id <= end) {
                ++ans;
                break;
            }
        }
    }
    cout << ans << '\n';
}
