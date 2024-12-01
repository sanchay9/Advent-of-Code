#include <iostream>
using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> left_list, right_list;

    int x, y;
    while (cin >> x >> y) {
        left_list.push_back(x);
        right_list.push_back(y);
    }

    sort(left_list.begin(), left_list.end());
    sort(right_list.begin(), right_list.end());

    int list_len = static_cast<int>(left_list.size());

    int ans = 0;
    for (int i = 0; i < list_len; i++) {
        ans += abs(left_list[i] - right_list[i]);
    }

    cout << ans << '\n';
}
