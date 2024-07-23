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

vector<pair<char, ll>> runLengthEncoding(string s) {
    vector<pair<char, ll>> ret;
    ll N = s.length();

    char prev = s[0];
    ll cnt = 1;
    for (int i = 1; i < N; i++) {
        if (prev == s[i]) {
            cnt++;
        } else {
            ret.push_back({prev, cnt});
            cnt = 1;
        }
        prev = s[i];
    }
    ret.push_back({prev, cnt});

    return ret;
}

int main() {
    long long N;
    cin >> N;
    long long K;
    cin >> K;
    string S;
    cin >> S;
    ll L = 0;

    auto calc = runLengthEncoding(S);
    ll ans = 0;
    ll cnt = 0;
    ll zero = 0;
    int size = calc.size();

    for (int i = 0; i < size; i++) {
        cnt += calc[i].second;
        if (calc[i].first == '0') {
            zero++;
        }
        while (K < zero) {
            cnt -= calc[L].second;
            if (calc[L].first == '0') {
                zero--;
            }
            L++;
        }
        ans = max(ans, cnt);
    }
    cout << ans;

    return 0;
}
