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

    string s; cin >> s;
    int n = s.size();

    for (int i = 13; i < n; i++) {
        set<char> st;

        for (int j = i; j >= i - 13; j--) {
            st.insert(s[j]);
        }

        if (st.size() == 14) {
            cout << i + 1 << '\n';
            return 0;
        }
    }
}
