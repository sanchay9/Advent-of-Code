#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int ans = 0;

    string s;
    while (cin >> s) {
        vector<string> machine(10);
        for (auto &x : machine) {
            cin >> x;
        }

        machine[1].pop_back();
        int ax = stoll(machine[1].substr(2));
        int ay = stoll(machine[2].substr(2));

        machine[5].pop_back();
        int bx = stoll(machine[5].substr(2));
        int by = stoll(machine[6].substr(2));

        machine[8].pop_back();
        int prizex = stoll(machine[8].substr(2));
        int prizey = stoll(machine[9].substr(2));

        int bdiff = (ay * bx) - (ax * by);
        int prizediff = (ay * prizex) - (ax * prizey);

        if ((bdiff > 0 && prizediff < 0) || (bdiff < 0 && prizediff > 0) ||
            (prizediff % bdiff != 0)) {
            continue;
        }
        int b = prizediff / bdiff;

        int arhs = prizex - (b * bx);
        if (arhs % ax != 0) {
            continue;
        }
        int a = arhs / ax;

        ans += 3 * a + b;
    }

    cout << ans << '\n';
}
