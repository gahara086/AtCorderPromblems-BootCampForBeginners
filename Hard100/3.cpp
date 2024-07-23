#include <bits/stdc++.h>

#include <algorithm>  // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <bitset>     // bitset
#include <cctype>     // isupper, islower, isdigit, toupper, tolower
#include <cstdint>    // int64_t, int*_t
#include <cstdio>     // printf
#include <deque>      // deque
#include <iostream>   // cout, endl, cin
#include <map>        // map
#include <queue>      // queue, priority_queue
#include <set>        // set
#include <stack>      // stack
#include <string>     // string, to_string, stoi
#include <tuple>      // tuple, make_tuple
#include <unordered_map>  // unordered_map
#include <unordered_set>  // unordered_set
#include <utility>        // pair, make_pair
#include <vector>         // vector
using namespace std;

bool debug_flag = true;

void logint1(int n) {
    if (debug_flag) cout << "arg_1 = " << n << endl;
}
void logint2(int n, int m) {
    if (debug_flag) cout << "arg_1 = " << n << " arg_2 = " << m << endl;
}
void logint3(int n, int m, int l) {
    if (debug_flag)
        cout << "arg_1 = " << n << " arg_2 = " << m << " arg_3 = " << l << endl;
}

void logstr1(string n) {
    if (debug_flag) cout << "arg_1 = " << n << endl;
}
void logstr2(string n, string m) {
    if (debug_flag) cout << "arg_1 = " << n << " arg_2 = " << m << endl;
}
void logstr3(string n, string m, string l) {
    if (debug_flag)
        cout << "arg_1 = " << n << " arg_2 = " << m << " arg_3 = " << l << endl;
}

int main() {
    long long H;
    cin >> H;
    long long W;
    cin >> W;

    char A[H + 1][W + 1];
    long long dp[H + 1][W + 1];
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> A[i][j];
            dp[i][j] = 0;
        }
    }

    if (A[1][1] == '#') {
        dp[1][1]++;
    }
    for (int i = 1; i < H; i++) {
        if (A[i + 1][1] == '#' && A[i][1] == '.') {
            dp[i + 1][1] = dp[i][1] + 1;
        } else {
            dp[i + 1][1] = dp[i][1];
        }
    }
    for (int i = 1; i < W; i++) {
        if (A[1][i + 1] == '#' && A[1][i] == '.') {
            dp[1][i + 1] = dp[1][i] + 1;
        } else {
            dp[1][i + 1] = dp[1][i];
        }
    }

    for (int i = 1; i < H; i++) {
        for (int j = 1; j < W; j++) {
            long long temp_3 = min(dp[i][j + 1], dp[i + 1][j]);
            long long temp = -1;
            if (A[i + 1][j + 1] == '#' && A[i + 1][j] == '.') {
                temp = dp[i + 1][j] + 1;
            } else if (A[i + 1][j + 1] == '#' && A[i + 1][j] == '#') {
                temp = dp[i + 1][j];
            }
            long long temp2 = -1;
            if (A[i + 1][j + 1] == '#' && A[i][j + 1] == '.') {
                temp2 = dp[i][j + 1] + 1;
            } else {
                temp2 = dp[i][j + 1];
            }
            if (A[i + 1][j + 1] == '#') {
                dp[i + 1][j + 1] = min(temp, temp2);
            } else {
                dp[i + 1][j + 1] = temp_3;
            }
        }
    }

    // for Debug
    // cout << "----------" << endl;
    // for (int i = 1; i <= H; i++) {
    //     for (int j = 1; j <= W; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    long long tempAns = abs((H + W - 1) - dp[H][W]);
    // long long tempAns = abs((H + W) - dp[H][W]);
    long long ans = min(tempAns, dp[H][W]);
    // cout << "dp[H][W] = " << dp[H][W] << endl;

    // cout << "tempAns = " << tempAns << endl;
    // cout << ans;
    cout << dp[H][W];

    return 0;
}
