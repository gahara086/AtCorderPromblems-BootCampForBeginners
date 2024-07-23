#include <bits/stdc++.h>

#include <algorithm>  // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <bitset>     // bitset
#include <cassert>
#include <cctype>         // isupper, islower, isdigit, toupper, tolower
#include <cstdint>        // int64_t, int*_t
#include <cstdio>         // printf
#include <deque>          // deque
#include <iostream>       // cout, endl, cin
#include <map>            // map
#include <numeric>        // gcd
#include <queue>          // queue, priority_queue
#include <set>            // set
#include <stack>          // stack
#include <string>         // string, to_string, stoi
#include <tuple>          // tuple, make_tuple
#include <unordered_map>  // unordered_map
#include <unordered_set>  // unordered_set
#include <utility>        // pair, make_pair
#include <vector>         // vector
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    // int N;
    long long N;
    cin >> N;

    long long X[N + 1];
    long long Y[N + 1];
    pair<long long, long long> pos[N + 1];
    bool flag[N + 1];
    for (int i = 0; i < N; i++) {
        cin >> X[i];
        cin >> Y[i];
        pos[i].first = X[i];
        pos[i].second = Y[i];
        flag[i] = false;
    }

    long long ans = N;
    rep(i, N) {
        rep(j, N) {
            if (i == j) {
                continue;
            }
            long long dx = X[i] - X[j];
            long long dy = Y[i] - Y[j];
            long long cnt = 0;
            rep(k, N) {
                rep(l, N) {
                    if (k == l) {
                        continue;
                    }
                    if (dx == X[k] - X[l] && dy == Y[k] - Y[l]) {
                        cnt++;
                    }
                }
            }
            ans = min(ans, N - cnt);
        }
    }
    cout << ans;

    return 0;
}
