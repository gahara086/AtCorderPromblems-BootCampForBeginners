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

const long long MOD = 1e+09 + 7;
// const long long MOD = 1000000007;
int facctorialMethod(int k) {
    int sum = 1;
    for (int i = 1; i <= k; ++i) {
        sum = sum % MOD * i % MOD;
    }
    return sum;
}
int main() {
    // int N;
    long long N;
    cin >> N;
    // int M;
    long long M;
    cin >> M;

    // const long long MOD = 1e+09 + 7;
    // cout << "MOD = " << MOD << endl;

    long long NG = abs(N - M);
    if (NG >= 2) {
        int ans = 0;
        cout << ans;
        return 0;
    }
    long long calc_N;
    long long calc_M;
    long long ans;
    if (NG == 1) {
        calc_N = facctorialMethod(N);
        calc_M = facctorialMethod(M);
        ans = calc_M * calc_N % MOD;
    }
    if (NG == 0) {
        calc_N = facctorialMethod(N);
        calc_M = facctorialMethod(M);
        ans = calc_M * calc_N * 2 % MOD;
    }
    cout << ans;

    return 0;
}
