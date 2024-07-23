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

    long long A[N + 1];
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    long long ans_N = 0;
    long long ans[N + 1];
    for (int i = 0; i <= N; i++) {
        ans[i] = 0;
    }

    vector<long long> ans_vec;
    for (int i = N; i > 0; i--) {
        // for (int i = 1; i <= N; i++) {
        long long temp = 0;  // 倍数の箱のボールの数の合計
        long long cnt = i;   // 倍数カウント用
        // if (A[i] == 1) {
        //     temp = 1;
        // }
        while (true) {
            temp += ans[cnt];
            cnt += i;
            if (cnt > N) {
                break;
            }
        }
        // cout << "cnt = " << cnt << endl;
        if (temp % 2 == A[i]) {
            continue;
        } else {
            ans_vec.push_back(i);
            ans[i] = 1;
            temp++;
        }
        // cout << "temp = " << temp << endl;
        // cnt = i;
        // while (true) {
        //     if (temp % 2 != A[cnt]) {
        //         cout << -1;
        //         return 0;
        //     }
        //     cnt += i;
        //     if (cnt > N) {
        //         break;
        //     }
        // }

        // if (temp % 2 != A[i]) {
        //     cout << -1;
        //     return 0;
        // }

        //  else if (A[i] == 1 && temp % 2 == ) {
        //     ans[i] = 1;
        // } else if (A[i] == 1 && temp % 2 == 1) {
        //     // ans[i] = 1;
        //     cout << -1;
        //     return 0;
        // } else if (A[i] == 0 && temp % 2 == 1) {
        // }
    }
    if (ans_vec.size() == 0) {
        cout << 0;
    } else {
        cout << ans_vec.size() << endl;
        for (int i = ans_vec.size() - 1; i >= 0; i--) {
            cout << ans_vec[i] << ' ';
        }
    }

    // for (int i = N; i > 0; i--) {
    //     if (ans[i] == 1) {
    //         ans_N = i;
    //         break;
    //     }
    // }
    // cout << ans_N << endl;
    // for (int i = 1; i <= ans_N; i++) {
    //     cout << ans[i] << ' ';
    // }

    return 0;
}
