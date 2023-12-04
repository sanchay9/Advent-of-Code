#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    auto process = [&](string& s) {
        int n = static_cast<int>(s.size());
        vector<vector<int>> game;
        int i = static_cast<int>(s.find(':'));
        while (i < n) {
            vector<int> rgb(3);
            do {
                i += 2;
                int cnt = stoll(s.substr(i, s.find(' ', i + 1) - i));
                i = static_cast<int>(s.find(' ', i + 1)) + 1;
                int start = i;
                while (i < n && s[i] >= 'a' && s[i] <= 'z') ++i;
                string color = s.substr(start, i - start);

                if (color == "red") {
                    rgb[0] = cnt;
                } else if (color == "green") {
                    rgb[1] = cnt;
                } else {
                    rgb[2] = cnt;
                }
            } while (s[i] == ',');
            game.push_back(rgb);
        }
        return game;
    };

    int id = 1;
    int ans = 0;
    string line;
    while (getline(cin, line)) {
        vector<vector<int>> game = process(line);
        bool ok = true;
        for (auto x : game) {
            if (x[0] > 12 || x[1] > 13 || x[2] > 14) {
                ok = false;
                break;
            }
        }
        if (ok) ans += id;
        ++id;
    }
    cout << ans << '\n';
}
