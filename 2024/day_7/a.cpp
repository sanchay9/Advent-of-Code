#include <bits/stdc++.h>
using namespace std;
#define int int64_t

bool backtrack(int idx, vector<int>& nums, int cur, int test_value) {
    if (idx == nums.size()) {
        return cur == test_value;
    }

    if (cur > test_value) {
        return false;
    }

    if (backtrack(idx + 1, nums, cur + nums[idx], test_value)) {
        return true;
    }

    if (backtrack(idx + 1, nums, cur * nums[idx], test_value)) {
        return true;
    }

    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int ans = 0;

    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        string tmp;

        getline(ss, tmp, ' ');
        tmp.pop_back();
        int test_value = stoll(tmp);

        vector<int> nums;
        while (getline(ss, tmp, ' ')) {
            nums.push_back(stoll(tmp));
        }

        if (backtrack(1, nums, nums[0], test_value)) {
            ans += test_value;
        }
    }

    cout << ans << '\n';
}
