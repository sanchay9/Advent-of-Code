#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string disk_map;
    cin >> disk_map;

    int n = static_cast<int>(disk_map.size());

    vector<int> nums;
    int id = 0;
    for (int i = 0; i < n; i += 2) {
        int block_size = disk_map[i] - '0';
        while (block_size--) {
            nums.push_back(id);
        }
        id++;
    }

    int sz = static_cast<int>(nums.size());
    int lo = 0, hi = sz - 1;

    int ans = 0;
    int position = 0;
    for (int i = 0; i < n && position < sz; i++) {
        if (i & 1) {
            for (int j = 0; j < disk_map[i] - '0' && position < sz; j++) {
                ans += (nums[hi--]) * (position++);
            }
        } else {
            for (int j = 0; j < disk_map[i] - '0' && position < sz; j++) {
                ans += (nums[lo++]) * (position++);
            }
        }
    }
    cout << ans << '\n';
}
