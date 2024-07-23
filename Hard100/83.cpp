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
    long long H;
    cin >> H;
    // int W;
    long long W;
    cin >> W;

    string A[H + 1];
    for (int i = 0; i < H; i++) {
        cin >> A[i];
    }

    // queueで'#'の箇所を格納してその周りを幅優先探索で増やしていく
    bool seen[H + 1][W + 1];
    bool flag = true;
    rep(i, 0, H) {
        rep(j, 0, W) {
            if (A[i][j] == '#') {
                seen[i][j] = true;
            } else {
                seen[i][j] = false;
                flag = false;
            }
        }
    }
    if (flag) {
        // 全部埋まってる場合
        cout << 0;
        return 0;
    }

    ll ans = 0;
    queue<vector<pair<ll, ll>>> que;
    vector<pair<ll, ll>> f;
    rep(i, 0, H) {
        rep(j, 0, W) {
            if (A[i][j] == '#') {
                f.push_back({i, j});
            }
        }
    }
    que.emplace(f);
    vector<ll> joge = {1, 0, -1, 0};
    vector<ll> sayu = {0, 1, 0, -1};

    while (que.size() != 0) {
        vector<pair<ll, ll>> state = que.front();
        que.pop();
        vector<pair<ll, ll>> s;
        for (auto next : state) {
            rep(i, 0, 4) {
                // 範囲内か判定
                if (0 <= next.F + joge[i] && next.F + joge[i] < H &&
                    0 <= next.S + sayu[i] && next.S + sayu[i] < W) {
                    // 探索済かどうか
                    if (!seen[next.F + joge[i]][next.S + sayu[i]]) {
                        seen[next.F + joge[i]][next.S + sayu[i]] = true;
                        s.push_back({next.F + joge[i], next.S + sayu[i]});
                    }
                }
            }
        }
        // 未探索の箇所があった場合、queを追加
        if (s.size() != 0) {
            que.emplace(s);
        }
        // 探索完了の場合終終了
        if (que.size() == 0) {
            break;
        }
        // 操作回数を増やす
        ans++;
    }
    cout << ans;

    return 0;
}
