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
unsigned GetDigit(unsigned num) { return log10(num) + 1; }

int main() {
    long long N;
    cin >> N;

    // 3進数で全パターンを列挙して判定を行う
    ll digit = GetDigit(N);

    const vector<ll> base{3, 5, 7};
    ll ans = 0;
    rep(i, 10) {
        // cout << i << endl;
        // 3進数を作る
        int shinsu_3 = 1;
        rep(j, i) shinsu_3 *= 3;

        rep(j, shinsu_3) {  // 3進数をビット探索
            int x = 0;      // 判定用の答え
            int msk = j;    // 3進数
            vector<ll> cnt = {0, 0, 0};
            rep(k, i) {           // 桁数分ループ
                int d = msk % 3;  // 3進数のどのビットが立っているか取得
                x = x * 10 + base[d];
                cnt[d]++;
                msk = msk / 3;  // 3進数を勧める
            }
            if (x <= N && 0 < cnt[0] && 0 < cnt[1] && 0 < cnt[2]) {
                ans++;
            }
        }
    }
    cout << ans;

    return 0;
}
