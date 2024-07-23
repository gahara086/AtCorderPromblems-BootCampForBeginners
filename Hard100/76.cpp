﻿#include <bits/stdc++.h>

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
    string S;
    // string S[H + 1];
    cin >> S;

    int N = S.length();
    // cout << "N = " << N << endl;

    int num[N];

    // ビット探索で解く
    rep(i, N) { num[i] = (S[i] - (int)'0'); }
    // rep(i, N) { cout << i; }
    // cout << endl;
    // cout << num[N - 1] << endl;

    ll ans = 0;
    ll bit = pow(2, N - 1) - 1;
    // cout << bit << endl;

    for (int i = 0; i < (1 << (N - 1)); i++) {
        ll temp_ans = 0;
        ll temp_calc = num[0];
        for (int j = 0; j < N - 1; j++) {
            if (i & (1 << j)) {  // ビット探索
                // 1の場合は '+'の処理を行う
                temp_ans += temp_calc;
                // +する数字を0に初期化
                temp_calc = 0;
            }
            // 0 の場合は数字を×10して次の数字を足す
            temp_calc = temp_calc * 10 + num[j + 1];
        }
        temp_ans += temp_calc;
        ans += temp_ans;
    }
    cout << ans;

    return 0;
}
