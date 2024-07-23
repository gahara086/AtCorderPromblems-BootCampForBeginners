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
    long long H;
    cin >> H;
    long long W;
    cin >> W;

    string S[H + 1];

    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    int sum[H + 1][W + 1];
    int L[H + 1][W + 1];  // ある座標から左に何マス照らせるか
    int R[H + 1][W + 1];
    int D[H + 1][W + 1];
    int U[H + 1][W + 1];
    rep(i, H + 1) {
        rep(j, W + 1) {
            sum[i][j] = 0;
            L[i][j] = 0;
            R[i][j] = 0;
            D[i][j] = 0;
            U[i][j] = 0;
        }
    }

    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == '.') {
                if (j == 0) {
                    L[i][j] = 1;
                } else {
                    L[i][j] = L[i][j - 1];
                    L[i][j]++;
                }
            }
        }
    }
    rep(i, H) {
        rrep(j, W) {
            if (S[i][j] == '.') {
                if (j == W - 1) {
                    R[i][j] = 1;
                } else {
                    R[i][j] = R[i][j + 1];
                    R[i][j]++;
                }
            }
        }
    }
    rep(j, W) {
        rep(i, H) {
            if (S[i][j] == '.') {
                if (i == 0) {
                    U[i][j] = 1;
                } else {
                    U[i][j] = U[i - 1][j];
                    U[i][j]++;
                }
            }
        }
    }
    rep(j, W) {
        rrep(i, H) {
            if (S[i][j] == '.') {
                if (i == H - 1) {
                    D[i][j] = 1;
                } else {
                    D[i][j] = D[i + 1][j];
                    D[i][j]++;
                }
            }
        }
    }
    // rep(i, H) {
    //     rrep(j, W) {
    //         if (S[i][j] == '.') {
    //             for (int k = j; k >= 0; k--) {
    //                 if (S[i][k] == '.') {
    //                     L[i][j]++;
    //                 } else {
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    // }

    // rep(j, W) {
    //     rep(i, H) {
    //         if (S[i][j] == '.') {
    //             for (int k = i; k < H; k++) {
    //                 if (S[k][j] == '.') {
    //                     D[i][j]++;
    //                 } else {
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    // }

    // rep(j, W) {
    //     rrep(i, H) {
    //         if (S[i][j] == '.') {
    //             for (int k = i; k >= 0; k--) {
    //                 if (S[k][j] == '.') {
    //                     U[i][j]++;
    //                 } else {
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    // }

    // rep(i, H) {
    //     rep(j, W) { cout << U[i][j] << ' '; }
    //     cout << endl;
    // }

    int ans = 0;
    rep(i, H) {
        rep(j, W) {
            int temp = R[i][j] + L[i][j] + D[i][j] + U[i][j] - 3;
            ans = max(ans, temp);
        }
    }
    cout << ans;

    return 0;
}
