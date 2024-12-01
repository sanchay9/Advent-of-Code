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
        vector<int> ans;
        int n;
        while (iss >> n) {
            ans.push_back(n);
        }
        return ans;
    };

    getline(cin, line);
    vector<int> time = parseLine(line);
    getline(cin, line);
    vector<int> dist = parseLine(line);

    int n = static_cast<int>(time.size());

    // t time           x sec hold , (t - x) * x
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int hold = 0; hold <= time[i]; hold++) {
            if (hold * (time[i] - hold) > dist[i]) {
                ++cnt;
            }
        }
        ans *= cnt;
    }
    cout << ans << '\n';
}
