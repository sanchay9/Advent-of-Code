#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    cin >> line;

    vector<pair<string, string>> ranges;
    stringstream ss(line);
    string range;
    while (getline(ss, range, ',')) {
        size_t dash_pos = range.find('-');
        string start = range.substr(0, dash_pos);
        string end = range.substr(dash_pos + 1);
        ranges.emplace_back(start, end);
    }

    multiset<int64_t> anss;
    for (const auto& [start, end] : ranges) {
        set<int64_t> candidates;
        for (int32_t p = 0; p < 6; p++) {
            int64_t lo = powl(10, p);
            int64_t hi = powl(10, p + 1) - 1;

            if (lo > stoll(end)) {
                break;
            }

            for (int64_t i = lo; i <= hi; i++) {
                for (int repeat = 2; repeat <= 10; repeat++) {
                    string candidate;
                    for (int k = 0; k < repeat; k++) {
                        candidate += to_string(i);
                    }

                    if (stoll(candidate) > stoll(end)) {
                        break;
                    }

                    if (stoll(candidate) >= stoll(start)) {
                        candidates.insert(stoll(candidate));
                    }
                }
            }
        }
        anss.insert(candidates.begin(), candidates.end());
    }

    int64_t ans = 0;
    for (auto x : anss) {
        ans += x;
    }
    cout << ans << '\n';
}
