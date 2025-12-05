#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<int64_t, int64_t>> ranges;

    string line;
    while (getline(cin, line)) {
        if (line.empty()) break;

        size_t dash_pos = line.find('-');
        string start = line.substr(0, dash_pos);
        string end = line.substr(dash_pos + 1);
        ranges.emplace_back(stoll(start), stoll(end));
    }

    ranges::sort(ranges);

    int n = static_cast<int>(ranges.size());
    for (int i = 1; i < n; i++) {
        if (ranges[i].first <= ranges[i - 1].second) {
            ranges[i].first = ranges[i - 1].first;
            ranges[i].second = max(ranges[i - 1].second, ranges[i].second);

            ranges.erase(ranges.begin() + i - 1);
            --i;
        }
    }

    int64_t ans = 0;
    for (const auto& [start, end] : ranges) {
        ans += end - start + 1;
    }

    cout << ans << '\n';
}
