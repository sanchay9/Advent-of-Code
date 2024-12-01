#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<string, int>> hands;
    string hand;
    int bid;
    while (cin >> hand >> bid) {
        hands.emplace_back(hand, bid);
    }

    auto card_strength = [](char c) {
        string all_cards = "AKQJT98765432J";
        reverse(all_cards.begin(), all_cards.end());
        return all_cards.find(c);
    };

    auto hand_strength = [](string &s) -> int {
        map<char, int> mp;
        for (auto x : s) ++mp[x];
        int mx = 0;
        for (auto x : mp) mx = max(mx, x.second);
        if (mp.size() == 1) return 7;
        if (mp.size() == 2) {
            if (mx == 4) return 6;
            return 5;
        }
        if (mp.size() == 3) {
            if (mx == 3) return 4;
            return 3;
        }
        if (mp.size() == 4) return 2;
        return 1;
    };

    sort(hands.begin(),
         hands.end(),
         [&](pair<string, int> &x, pair<string, int> &y) {
             if (hand_strength(x.first) == hand_strength(y.first)) {
                 for (int i = 0; i < 5; i++) {
                     if (card_strength(y.first[i]) !=
                         card_strength(x.first[i])) {
                         return card_strength(y.first[i]) >
                                card_strength(x.first[i]);
                     }
                 }
             }
             return hand_strength(x.first) < hand_strength(y.first);
         });

    int n = static_cast<int>(hands.size());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += hands[i].second * (i + 1);
    }
    cout << ans << '\n';
}
