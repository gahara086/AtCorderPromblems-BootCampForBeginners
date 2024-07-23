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
template <typename T>

T mod_pow(T x, T n, const T &p) {
    T ret = 1;
    while (n > 0) {
        if (n & 1) (ret *= x) %= p;
        (x *= x) %= p;
        n >>= 1;
    }
    return ret;
}
int main() {
    long long MOD = 998244353;
    long long N;
    cin >> N;

    long long A[N + 1];
    vector<long long> A_v;
    long long max_A = -1;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        A_v.push_back(A[i]);
        max_A = max(max_A, A[i]);
    }
    if (A[1] != 0) {
        cout << 0;
        return 0;
    }

    map<long long, long long> cnt;
    cnt[0] = 0;
    for (int i = 1; i <= max_A; i++) {
        cnt[i] = 0;
    }
    for (int i = 1; i <= N; i++) {
        cnt[A[i]]++;
    }
    cnt[max_A + 1] = 0;
    if (cnt[0] != 1) {
        cout << 0;
        return 0;
    }

    long long ans = 1;
    for (int i = 1; i <= max_A + 1; i++) {
        ans = ans * mod_pow(cnt[i - 1], cnt[i], MOD);
        ans = ans % MOD;
    }

    cout << ans;

    return 0;
}
