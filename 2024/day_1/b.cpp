#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> left_list;
    map<int, int> right_counts;

    int left, right;
    while (cin >> left >> right) {
        left_list.push_back(left);
        ++right_counts[right];
    }

    int ans = 0;
    for (auto x : left_list) {
        ans += x * right_counts[x];
    }
    cout << ans << '\n';
}
