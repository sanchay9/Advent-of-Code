#include <iostream>
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 100;

    int ans = 0, cur = 50;

    string line;
    while (getline(cin, line)) {
        int distance = stoi(line.substr(1));

        ans += distance / N;
        distance %= N;

        if (line[0] == 'R') {
            if (cur != 0 && cur + distance > N) {
                ++ans;
            }
            cur = (cur + distance) % N;
        } else {
            if (cur != 0 && cur - distance < 0) {
                ++ans;
            }
            cur = (cur - distance + N) % N;
        }

        if (cur == 0) {
            ++ans;
        }
    }

    cout << ans << '\n';
}
