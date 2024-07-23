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
    // int N;
    long long N;
    cin >> N;
    ll cnt[10][10];
    rep(i, 10) {
        rep(j, 10) { cnt[i][j] = 0; }
    }

    rep(i, N + 1) {
        if (i == 0) {
            continue;
        }
        ll bottom = i % 10;
        ll top;
        ll temp = i;
        while (true) {
            if (temp / 10 == 0) {
                break;
            } else {
                temp /= 10;
            }
        }
        top = temp;
        // cout << "i   = " << i << endl;
        // cout << "top = " << top << endl;
        // cout << "bot = " << bottom << endl;
        cnt[top][bottom]++;
    }

    ll ans = 0;
    rep(top, 10) {
        rep(bottom, 10) {
            // if (top == bottom) {
            // cout << "top = " << top << endl;
            // cout << "cnt[top][bottom] = " << cnt[top][bottom] << endl;
            // cout << "cnt[bottom][top] = " << cnt[bottom][top] << endl;
            ans += cnt[top][bottom] * cnt[bottom][top];
            // }
        }
    }
    cout << ans;

    return 0;
}
