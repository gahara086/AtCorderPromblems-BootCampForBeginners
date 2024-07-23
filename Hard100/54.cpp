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
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

// 長いのは全部短く
#define pb push_back
#define mp make_pair
#define F first
#define S second

// 打ち間違え防止
#define itn int

// 今はまだ早いマクロ
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
    ll X;
    ll Y;
    ll A;
    ll B;
    ll C;
    cin >> X >> Y >> A >> B >> C;

    vector<ll> p;
    vector<ll> q;
    vector<ll> r;

    for (int i = 0; i < A; i++) {
        ll temp;
        cin >> temp;
        p.push_back(temp);
    }
    for (int i = 0; i < B; i++) {
        ll temp;
        cin >> temp;
        q.push_back(temp);
    }
    for (int i = 0; i < C; i++) {
        ll temp;
        cin >> temp;
        r.push_back(temp);
    }

    sort(rall(p));
    sort(rall(q));
    sort(rall(r));

    vector<ll> new_apple;

    rep(i, X) { new_apple.push_back(p[i]); }
    rep(i, Y) { new_apple.push_back(q[i]); }
    rep(i, C) { new_apple.push_back(r[i]); }
    sort(rall(new_apple));

    ll ans = 0;
    rep(i, X + Y) { ans += new_apple[i]; }
    cout << ans;

    return 0;
}
