#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    auto parseSeeds = [](string &line) {
        istringstream iss(line);
        string s;
        iss >> s;
        vector<int> seeds;
        int n;
        while (iss >> n) seeds.push_back(n);
        return seeds;
    };

    auto insertMapping = [](map<pair<int, int>, int> &mp, string &line) {
        istringstream iss(line);
        int n1, n2, n3;
        iss >> n1 >> n2 >> n3;
        mp[{n2, n2 + n3 - 1}] = n1;
    };

    string line;
    getline(cin, line);
    vector<int> seeds = parseSeeds(line);

    vector<map<pair<int, int>, int>> maps;
    map<pair<int, int>, int> map;
    while (getline(cin, line)) {
        if (line.empty()) continue;

        if (line[0] >= 'a' && line[0] <= 'z') {
            if (!map.empty()) maps.push_back(map);
            map.clear();
        } else {
            insertMapping(map, line);
        }
    }
    if (!map.empty()) maps.push_back(map);

    auto location = [&](int seed) {
        for (const auto &x : maps) {
            for (auto [k, v] : x) {
                if (seed >= k.first && seed <= k.second) {
                    seed = v + (seed - k.first);
                    break;
                }
            }
        }
        return seed;
    };

    int min_location = 1e9;
    for (auto seed : seeds) {
        min_location = min(min_location, location(seed));
    }
    cout << min_location << '\n';
}
