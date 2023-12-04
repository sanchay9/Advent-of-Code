#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    auto isDigit = [&](string &s, int i) {
        return s[i] >= '0' && s[i] <= '9';
    };

    auto num = [&](string &s, int &i) {
        int n = static_cast<int>(s.size());
        string tmp;
        while (i < n && isDigit(s, i)) {
            tmp.push_back(s[i++]);
        }
        return stoll(tmp);
    };

    int ans = 0;
    string line;
    while (getline(cin, line)) {
        int n = static_cast<int>(line.size());
        map<int, bool> winning;

        int i = static_cast<int>(line.find(':')) + 1;
        while (line[i + 1] != '|') {
            while (line[i] == ' ') ++i;
            winning[num(line, i)] = false;
        }
        i += 3;
        while (i < n) {
            while (line[i] == ' ') ++i;
            int N = num(line, i);
            if (winning.find(N) != winning.end()) {
                winning[N] = true;
            }
        }
        int cnt = 0;
        for (auto x : winning) {
            cnt += x.second;
        }
        if (cnt) ans += (1LL << (cnt - 1));
    }
    cout << ans << '\n';
}
