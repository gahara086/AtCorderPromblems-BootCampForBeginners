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

const long long MOD = 1000000007;
int main() {
    // int N;
    long long N;
    cin >> N;
    // int M;
    long long M;
    cin >> M;

    bool ng[100009];
    for (int i = 0; i <= 100005; i++) {
        ng[i] = false;
    }
    for (int i = 1; i <= M; i++) {
        long long temp;
        cin >> temp;
        ng[temp] = true;
    }

    long long dp[100009];
    for (int i = 0; i <= 100005; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;
    // dp[1] = 1;
    // 試験的にDPで10段目までの階段の通りを表示
    for (int i = 0; i <= N - 1; i++) {
        if (dp[i] > 0) {
            if (ng[i + 1] == true) {
            } else {
                dp[i + 1] = dp[i + 1] % MOD;
                dp[i + 1] += dp[i];
            }
            if (ng[i + 2] == true) {
            } else {
                dp[i + 2] = dp[i + 2] % MOD;
                dp[i + 2] += dp[i];
            }
        }
        // cout << "dp[" << i << "] = " << dp[i] << endl;
    }
    cout << dp[N] % MOD;
    // cout << "dp[3] = " << dp[3] << endl;
    return 0;
}
