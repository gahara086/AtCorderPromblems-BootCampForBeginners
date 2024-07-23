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
    int N;
    cin >> N;

    int C[N + 1];
    int S[N + 1];
    int F[N + 1];
    for (int i = 0; i < N - 1; i++) {
        cin >> C[i];
        cin >> S[i];
        cin >> F[i];
    }

    int dp[N + 1];
    dp[0] = 0;
    int ans[N + 1];
    for (int i = 0; i < N - 1; i++) {
        for (int j = i; j < N - 1; j++) {
            if (dp[j] <= S[j]) {
                dp[j + 1] = S[j] + C[j];
            } else {
                int temp = dp[j] % F[j];
                if (temp == 0) {
                    dp[j + 1] = dp[j] + C[j];
                } else {
                    temp = F[j] - temp;
                    dp[j + 1] = dp[j] + temp + C[j];
                }
            }
            // if (j = N - 1) {
            // ans[i] = dp[N - 1];
            // }
            ans[i] = dp[N - 1];
        }
        for (int k = 0; k < N; k++) {
            dp[k] = 0;
        }
        dp[i] = 0;
        dp[i + 1] = 0;
        // if (dp[i] <= S[i]) {
        //     dp[i + 1] = S[i] + C[i];
        // } else {
        //     int temp = dp[i] % F[i];
        //     if (temp == 0) {
        //         dp[i + 1] = dp[i] + C[i];
        //     } else {
        //         temp = F[i] - temp;
        //         dp[i + 1] = dp[i] + temp + C[i];
        //     }
        // }
    }
    ans[N - 1] = 0;

    // for (int i = N - 1; i >= 0; i--) {
    // cout << dp[i] << endl;
    // cout << ans[i] << endl;
    // }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
