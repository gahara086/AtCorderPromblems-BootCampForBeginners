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
    cin >> S;
    long long K;
    cin >> K;

    int N = S.length();
    // map<string, int> cnt;
    // set<string> cnt;
    vector<string> cnt;

    rep(i, N) {
        for (int j = 1; j < 6; j++) {
            cnt.push_back(S.substr(i, j));
        }
        // string temp = "";
        // rep(j, 5) {
        //     temp = temp + S[i + j];  // ここが戦犯
        //     cnt.push_back(temp);
        // }
    }
    sort(cnt.begin(), cnt.end());
    cnt.erase(unique(cnt.begin(), cnt.end()), cnt.end());

    // rep(i, cnt.size()) { cout << cnt[i] << endl; }

    cout << cnt[K - 1];

    return 0;
}
