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

        if (line[0] == 'R') {
            cur = (cur + distance) % N;
        } else {
            cur = (cur - distance + N) % N;
        }

        if (cur == 0) {
            ++ans;
        }
    }

    cout << ans << '\n';
}
