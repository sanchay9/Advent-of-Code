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

    int64_t ans = 0;
    for (const auto& [start, end] : ranges) {
        size_t start_len = start.size();
        size_t end_len = end.size();

        string first_half = start.substr(0, start_len / 2);
        if (start_len & 1) {
            ++start_len;
            first_half =
                to_string(static_cast<int64_t>(powl(10, (start_len / 2) - 1)));
        }
        if (end_len & 1) --end_len;

        for (size_t i = start_len; i <= end_len; i += 2) {
            while (true) {
                if (first_half.size() > i / 2 ||
                    stoll(first_half + first_half) > stoll(end)) {
                    break;
                }

                if (stoll(first_half + first_half) < stoll(start)) {
                    first_half = to_string(stoll(first_half) + 1);
                    continue;
                }

                ans += stoll(first_half + first_half);

                first_half = to_string(stoll(first_half) + 1);
            }
        }
    }
    cout << ans << '\n';
}
