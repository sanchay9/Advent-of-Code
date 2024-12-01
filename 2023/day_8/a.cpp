#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string path;
    getline(cin, path);
    int n = static_cast<int>(path.size());

    map<string, pair<string, string>> nodes;

    string line;
    getline(cin, line);
    while (getline(cin, line)) {
        nodes[line.substr(0, 3)] = {line.substr(7, 3), line.substr(12, 3)};
    }

    string cur = "AAA";
    int i = 0;
    int ans = 0;
    while (cur != "ZZZ") {
        if (path[i++ % n] == 'L') {
            cur = nodes[cur].first;
        } else {
            cur = nodes[cur].second;
        }
        ++ans;
    }
    cout << ans << '\n';
}
