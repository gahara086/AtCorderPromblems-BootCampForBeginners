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
    long long N;
    cin >> N;
    // int A[N+1];
    long long A[N + 1];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    if (N == 1) {
        if (A[0] == 0) {
            cout << 1;
            return 0;
        }
        cout << 0;
        return 0;
    }

    map<long long, long long> cnt;
    // for (int i = 0; i < N; i++) {
    //     cnt[i] = 0;
    // }
    for (int i = 0; i < N; i++) {
        cnt[A[i]]++;
    }
    auto begin = cnt.begin();
    auto end = cnt.end();
    for (auto iter = begin; iter != end; iter++) {
        // cout << iter->first << ": ";
        // cout << iter->second << endl;
        if (N % 2 == 1 && iter->first == 0 && iter->second != 1) {
            cout << 0;
            return 0;
        }
        if (N % 2 == 0 && iter->first == 0) {
            cout << 0;
            return 0;
        }

        if (iter->second != 2 && iter->first != 0) {
            cout << 0;
            return 0;
        }
    }
    // if (cnt[0] >= 2) {
    //     cout << 0;
    //     return 0;
    // }
    // if (N % 2 == 0 && cnt[0] >= 1) {
    //     cout << 0;
    //     return 0;
    // }
    // for (int i = 1; i < N; i++) {
    //     if (cnt[i] != 0 && cnt[i] != 2) {
    //         // cout << "i = " << i << endl;
    //         cout << 0;
    //         return 0;
    //     }
    //     if (cnt[i] != 0 && N % 2 == 1 && i % 2 == 1) {
    //         cout << 0;
    //         return 0;
    //     }
    //     if (cnt[i] != 0 && N % 2 == 0 && i % 2 == 0) {
    //         cout << 0;
    //         return 0;
    //     }
    // }
    long long ans = 0;
    // const long long MOD = 1000000000 + 7;
    const long long MOD = 1e+09 + 7;
    long long p = N / 2;
    ans = 2;
    for (int i = 1; i < p; i++) {
        ans = ans * 2 % MOD;
    }
    cout << ans;

    return 0;
}
