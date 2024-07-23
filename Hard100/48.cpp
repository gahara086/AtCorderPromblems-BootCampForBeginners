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
    long long H;
    cin >> H;
    long long N;
    cin >> N;

    int A[N + 1];
    int B[N + 1];
    pair<long long, long long> magic[N + 1];
    double cospa[N + 1];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        cin >> B[i];
    }

    // 動的計画法で解く
    int dp[N + 1][H + 1];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= H; j++) {
            dp[i][j] = 999999999;
        }
    }

    dp[0][H] = 0;
    for (int i = 0; i < N; i++) {
        for (int h = H; h >= 0; h--) {
            dp[i + 1][h] = dp[i][h];
            long long m = 0;
            long long temp = h - A[i];
            m = max(m, temp);
            dp[i][m] = min(dp[i][m], dp[i][h] + B[i]);
        }
    }

    cout << dp[N][0];
}
