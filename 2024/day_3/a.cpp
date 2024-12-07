#include <bits/stdc++.h>
using namespace std;
#define int int64_t

bool isValidIntString(string &s) {
    if (s.size() < 1 || s.size() > 3) {
        return false;
    }
    return all_of(s.begin(), s.end(), [](char c) {
        return (c >= '0' && c <= '9');
    });
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const string mul_prefix = "mul(", mul_suffix = ")";
    const char mul_sep = ',';

    int ans = 0;

    string line;
    while (getline(cin, line)) {
        int seq = 0;

        while (true) {
            int start = static_cast<int>(line.find(mul_prefix, seq));
            if (start == string::npos) {
                break;
            }

            seq = start + 1;

            int end = static_cast<int>(line.find(mul_suffix, start));

            int sep = static_cast<int>(line.find(mul_sep, start));
            if (sep > end || sep == string::npos) {
                continue;
            }

            string num1 = line.substr(start + mul_prefix.size(),
                                      sep - start - mul_prefix.size());
            string num2 = line.substr(sep + 1, end - sep - mul_suffix.size());

            if (!isValidIntString(num1) || !isValidIntString(num2)) {
                continue;
            }

            ans += static_cast<int>(stoi(num1) * stoi(num2));
        }
    }

    cout << ans << '\n';
}
