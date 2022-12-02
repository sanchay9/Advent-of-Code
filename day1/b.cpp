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
    priority_queue<int, vector<int>, greater<int> > pq;


    int cur = 0;
    while (getline(cin, line)) {
        if (line.size()) {
            cur += stoll(line);
        } else {
            pq.push(cur);
            if (pq.size() == 4) pq.pop();

            cur = 0;
        }
    }

    pq.push(cur);
    if (pq.size() == 4) pq.pop();

    int ans = 0;
    while (pq.size()) {
        ans += pq.top(); pq.pop();
    }

    cout << ans << '\n';
}
