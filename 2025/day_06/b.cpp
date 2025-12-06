#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> nums;

    string line;
    while (getline(cin, line)) {
        if (line.find_first_of("0123456789") == string::npos) {
            break;
        }

        nums.push_back(line);
    }

    int n = static_cast<int>(nums.size()), m = static_cast<int>(nums[0].size());

    vector<vector<int64_t>> new_nums;
    vector<int64_t> tmp;
    for (int j = 0; j < m; j++) {
        int64_t col = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i][j] != ' ') {
                col = (col * 10) + (nums[i][j] - '0');
            }
        }
        if (col == 0) {
            new_nums.push_back(tmp);
            tmp.clear();
        } else {
            tmp.push_back(col);
        }
    }
    new_nums.push_back(tmp);

    stringstream ss(line);
    int64_t ans = 0;
    for (auto& x : new_nums) {
        char c;
        ss >> c;
        assert(c == '+' || c == '*');

        if (c == '*') {
            int64_t prod = 1;
            for (auto& y : x) {
                prod *= y;
            }
            ans += prod;
        } else {
            int64_t sum = 0;
            for (auto& y : x) {
                sum += y;
            }
            ans += sum;
        }
    }
    cout << ans << '\n';
}
