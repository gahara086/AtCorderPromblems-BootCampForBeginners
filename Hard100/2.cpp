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
const long long DIV = 1e+09 + 7;
// const long long DIV = 1e+08 + 7;
// const long long DIV = 1e+07 + 7;

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

const long long MOD = 1e+09 + 7;
int main() {
    int N;
    cin >> N;

    int K;
    cin >> K;

    long long A[N + 1];
    vector<long long> A_v;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A_v.push_back(A[i]);
    }


    long long tento_cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i] > A[j]) {
                tento_cnt++;
            }
        }
    }
    cout << "tento_cnt = " << tento_cnt << endl;
    cout << "K = " << K << endl;
    K = K % MOD;
    cout << "K = " << K << endl;
    long long calc_max = tento_cnt * K;
    // long long calc_max = (tento_cnt % MOD) * K;
    // long long calc_max = ((tento_cnt % MOD) * K) % MOD;
    cout << "calc_max = " << calc_max << endl;
    long long ans = 0;
    // ans = (tento_cnt + calc_max) * K / 2;
    // ans = ((tento_cnt * K % MOD) + (calc_max * K % MOD)) / 2;
    // ans = (((tento_cnt + calc_max) / 2) * (K / 2 % MOD) % MOD);  // / 2;
    // ans = ans % MOD;
    K = K + 1;
    ans = (tento_cnt) * (K * (K - 1)) % MOD / 2 % MOD;
    // ans = (tento_cnt % MOD) * (K * (K - 1) % MOD) % MOD / 2 % MOD;

    // ans = (tento_cnt % MOD) * (K % MOD);

    cout << ans;

    return 0;
}
