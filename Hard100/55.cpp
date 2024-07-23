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
    long long N;
    cin >> N;
    long long A;
    cin >> A;
    long long B;
    cin >> B;
    long long X[N + 1];
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    ll dp[N + 1][2];
    rep(i, N + 1) {
        rep(j, 2) { dp[i][j] = 0; }
    }
    dp[0][0] = 0;
    dp[0][1] = 0;

    for (int i = 0; i < N - 1; i++) {
        ll A_kyori = (X[i + 1] - X[i]) * A;
        // cout << "A_kyori = " << A_kyori << endl;
        dp[i + 1][0] = min(dp[i][0], dp[i][1]) + A_kyori;
        dp[i + 1][1] = min(dp[i][0], dp[i][1]) + B;
    }
    cout << min(dp[N - 1][0], dp[N - 1][1]);

    return 0;
}
