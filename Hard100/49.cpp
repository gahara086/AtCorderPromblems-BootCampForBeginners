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
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    long long N;
    cin >> N;
    long long A;
    cin >> A;
    long long B;
    cin >> B;

    // 競技プログラミング用のヘッダファイルをインクルードしてから解ける
    const long long MOD = 1e+09 + 7;

    long long ans = modpow(2, N, MOD) - 1;
    cout << "ans = " << ans << endl;

    long long a = 1;
    long long temp_N = N;
    for (int i = A; i > 0; i--) {
        a = a * temp_N % MOD;
        // a = a / i % MOD;
        temp_N--;
    }
    for (int i = A; i > 0; i--) {
        a = a / i;
    }
    cout << "a = " << a << endl;

    long long b = 1;
    temp_N = N;
    for (int i = B; i > 0; i--) {
        b = (b * temp_N) % MOD;
        temp_N--;
    }
    for (int i = B; i > 0; i--) {
        b = b / i;
    }
    cout << "b =" << b << endl;

    ans = ans - a - b;

    cout << ans;
    return 0;
}
