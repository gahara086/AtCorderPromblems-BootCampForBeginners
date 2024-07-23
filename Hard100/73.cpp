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
int N;
//---------------------------------------------------------------------------------------------------
int memo[101010];
// 回数を戻り値都数r
int f(int cu) {
    if (cu == 0) return 0;
    if (memo[cu]) return memo[cu];

    int res = 99999;

    // 1yen でカウントする場合
    chmin(res, f(cu - 1) + 1);

    // 6yen でカウントする場合
    int x = 6;
    while (x <= cu) {
        chmin(res, f(cu - x) + 1);
        x *= 6;
    }

    // 9yen
    x = 9;
    while (x <= cu) {
        chmin(res, f(cu - x) + 1);
        x *= 9;
    }
    cout << "cu = " << cu << endl;
    memo[cu] = res;

    return res;
}
//---------------------------------------------------------------------------------------------------
int main() {
    // rep(i, 100) { cout << memo[i] << endl; }
    cin >> N;
    cout << f(N) << endl;
    // rep(i, 100) { cout << memo[i] << endl; }
    return 0;
}