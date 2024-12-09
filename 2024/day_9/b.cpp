#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string disk_map;
    cin >> disk_map;

    int n = static_cast<int>(disk_map.size());

    vector<int> blanks, nums;
    vector<int> blanksi, numsi;
    int idx = disk_map[0] - '0';
    for (int i = 1; i < n; i += 2) {
        blanks.push_back(disk_map[i] - '0');
        blanksi.push_back(idx);

        if (i + 1 < n) idx += disk_map[i] - '0' + disk_map[i + 1] - '0';
    }
    idx = 0;
    for (int i = 0; i < n; i += 2) {
        nums.push_back(disk_map[i] - '0');
        numsi.push_back(idx);

        if (i + 1 < n) idx += disk_map[i] - '0' + disk_map[i + 1] - '0';
    }

    int sznums = static_cast<int>(nums.size());
    int szblanks = static_cast<int>(blanks.size());

    int ans = 0;
    for (int i = sznums - 1; i >= 1; i--) {
        for (int j = 0; j < szblanks; j++) {
            if (blanks[j] >= nums[i] && blanksi[j] < numsi[i]) {
                blanks[j] -= nums[i];

                int position = blanksi[j];
                blanksi[j] += nums[i];

                for (int k = 0; k < nums[i]; k++) {
                    ans += i * (position++);
                }
                nums[i] = 0;
            }
        }
    }
    for (int i = 0; i < sznums; i++) {
        int position = numsi[i];
        for (int k = 0; k < nums[i]; k++) {
            ans += i * (position++);
        }
    }
    cout << ans << '\n';
}
