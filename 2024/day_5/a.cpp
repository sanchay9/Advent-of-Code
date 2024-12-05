#include <cctype>
#include <iostream>
#include <set>
#include <sstream>
using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    set<pair<int, int>> st;
    while (getline(cin, line)) {
        if (line.empty() || !isdigit(line[0])) {
            break;
        }
        int pipe = static_cast<int>(line.find('|'));

        int x = stoi(line.substr(0, pipe));
        int y = stoi(line.substr(pipe + 1));
        st.insert({x, y});
    }

    int ans = 0;
    while (getline(cin, line)) {
        stringstream ss(line);
        string tmp;
        vector<int> pages;

        while (getline(ss, tmp, ',')) {
            pages.push_back(stoi(tmp));
        }

        int n = static_cast<int>(pages.size());

        bool ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (st.find({pages[j], pages[i]}) != st.end()) {
                    ok = false;
                    break;
                }
            }
        }

        if (ok) {
            ans += pages[n / 2];
        }
    }

    cout << ans << '\n';
}
