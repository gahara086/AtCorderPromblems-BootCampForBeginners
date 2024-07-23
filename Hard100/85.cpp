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

// 習得するマクロ
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

// 長いのは全部短く
#define pb push_back
#define mp make_pair
#define F first
#define S second

// でかい数字
const int inf = INT_MAX / 2;
const ll infl = 1LL << 60;

// 最大値、最小値を更新する関数
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    long long N;
    cin >> N;

    long long X[N + 1];
    long long Y[N + 1];
    ll H[N + 1];
    for (int i = 0; i < N; i++) {
        cin >> X[i];
        cin >> Y[i];
        cin >> H[i];
    }

    rep(x, 0, 101) {
        rep(y, 0, 101) {
            ll h = 1;
            rep(i, 0, N) {
                if (H[i] != 0) {
                    h = H[i] + abs(x - X[i]) + abs(y - Y[i]);
                    // x,yが答えの場合、このhの値は不変になる
                    // cout << "h = " << h << endl;
                }
            }
            ll ok = true;
            rep(i, 0, N) {
                ll temp_h = max((h - abs(x - X[i]) - abs(y - Y[i])), (ll)0);
                if (temp_h != H[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << x << ' ' << y << ' ' << h;
                return 0;
            }
        }
    }
    cout << -1;

    return 0;
}
