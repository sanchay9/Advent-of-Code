#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    string line;

    int n;
    vector<vector<char> > a(105);
    while (getline(cin, line)) {
        if (line[1] == '1') {
            break;
        }

        ++n;

        int idx = 0;
        for (int i = 1; i < (int)line.size(); i += 4) {
            if (line[i] != ' ') {
                a[idx].push_back(line[i]);
            }

            ++idx;
        }
    }

    for (auto &x : a) {
        reverse(x.begin(), x.end());
    }

    getline(cin, line);
    while (getline(cin, line)) {
        string tmp = line.substr(5, 2);
        if (tmp.back() == ' ') tmp.pop_back();

        int cnt = stoll(tmp);

        int from = stoll(line.substr(line.find('r') + 4)) - 1;
        int to = stoll(line.substr(line.find('r') + 9)) - 1;

        queue<char> q;
        for (int i = 0; i < cnt; i++) {
            q.push(a[from].back());
            a[from].pop_back();
        }

        for (int i = 0; i < cnt; i++) {
            a[to].push_back(q.front());
            q.pop();
        }
    }

    string ans;
    for (auto x : a) {
        if (x.size()) ans.push_back(x.back());
    }

    cout << ans << '\n';
}
