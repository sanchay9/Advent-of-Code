#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 3;

    string path;
    getline(cin, path);
    int n = static_cast<int>(path.size());

    map<string, pair<string, string>> nodes;

    string line;
    getline(cin, line);

    vector<string> cur;
    while (getline(cin, line)) {
        if (line[N - 1] == 'A') cur.push_back(line.substr(0, N));
        nodes[line.substr(0, N)] = {line.substr(7, N), line.substr(12, N)};
    }

    vector<int> steps;
    for (auto &x : cur) {
        int i = 0;
        while (x.back() != 'Z') {
            if (path[i++ % n] == 'L') {
                x = nodes[x].first;
            } else {
                x = nodes[x].second;
            }
        }
        steps.push_back(i);
    }

    int ans = 1;
    for (auto x : steps) {
        ans = lcm(ans, x);
    }
    cout << ans << '\n';
}
