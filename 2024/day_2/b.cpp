#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int ans = 0;

    auto checkSafe = [](vector<int> &a) {
        bool unsafe = false;
        int num_levels = static_cast<int>(a.size());
        for (int i = 1; i < num_levels; i++) {
            int diff = abs(a[i] - a[i - 1]);
            if (diff < 1 || diff > 3) {
                unsafe = true;
            }
        }

        if (unsafe) return false;

        if (is_sorted(a.begin(), a.end()) || is_sorted(a.rbegin(), a.rend())) {
            return true;
        }
        return false;
    };

    string line;
    while (getline(cin, line)) {
        vector<int> levels;

        istringstream iss(line);
        int num;
        while (iss >> num) {
            levels.push_back(num);
        }

        int num_levels = static_cast<int>(levels.size());
        for (int i = 0; i < num_levels; i++) {
            vector<int> tmp = levels;
            tmp.erase(tmp.begin() + i);

            if (checkSafe(tmp)) {
                ++ans;
                break;
            }
        }
    }

    cout << ans << '\n';
}
