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
    // int N;
    long long N;
    cin >> N;
    long long H;
    cin >> H;
    long long A[N + 1];
    long long B[N + 1];
    long long max_A = -1;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        max_A = max(max_A, A[i]);

        cin >> B[i];
    }
    sort(B, B + N, greater<int>());
    long long cnt = 0;
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        if (B[i] >= max_A) {
            // cout << "B[i] = " << B[i] << endl;
            sum += B[i];
            cnt++;
        }
        if (sum >= H) {
            cout << cnt;
            return 0;
            break;
        }
        // if(B[i] >= max_A)
    }
    long long nokori = H - sum;
    if (nokori % max_A == 0) {
        nokori = nokori / max_A;
    } else {
        nokori = nokori / max_A;
        nokori++;
    }
    long long ans = cnt + nokori;
    cout << ans;

    // long long dp[N + 1][2];

    return 0;
}
