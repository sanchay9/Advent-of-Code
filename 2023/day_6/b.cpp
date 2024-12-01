#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;

    auto parseLine = [&](string &line) {
        istringstream iss(line);
        string s;
        iss >> s;

        string ans;
        while (iss >> s) {
            ans += s;
        }
        return stoll(ans);
    };

    getline(cin, line);
    int time = parseLine(line);
    getline(cin, line);
    int dist = parseLine(line);

    int ans = 0;
    for (int hold = 0; hold <= time; hold++) {
        if (hold * (time - hold) > dist) {
            ++ans;
        }
    }
    cout << ans << '\n';
}
