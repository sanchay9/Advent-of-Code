#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int64_t>> nums;

    string line;
    while (getline(cin, line)) {
        if (line.find_first_of("0123456789") == string::npos) {
            break;
        }

        vector<int64_t> row;
        stringstream ss(line);
        string token;
        while (ss >> token) {
            row.push_back(stoll(token));
        }
        nums.push_back(row);
    }

    stringstream ss(line);
    int64_t ans = 0;
    int n = static_cast<int>(nums.size()), m = static_cast<int>(nums[0].size());
    for (int p = 0; p < m; p++) {
        char c;
        ss >> c;
        assert(c == '+' || c == '*');

        if (c == '*') {
            int64_t prod = 1;
            for (int i = 0; i < n; i++) {
                prod *= nums[i][p];
            }
            ans += prod;
        } else {
            int64_t sum = 0;
            for (int i = 0; i < n; i++) {
                sum += nums[i][p];
            }
            ans += sum;
        }
    }
    cout << ans << '\n';
}
