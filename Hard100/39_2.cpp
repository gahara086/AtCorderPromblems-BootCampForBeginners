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
    long long N;
    cin >> N;
    string S;
    cin >> S;

    long long cntShiro[N + 1];
    long long cntKuro[N + 1];
    cntKuro[0] = 0;
    cntShiro[0] = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '#') {
            cntKuro[i + 1] = cntKuro[i] + 1;
            cntShiro[i + 1] = cntShiro[i];
        } else {
            cntKuro[i + 1] = cntKuro[i];
            cntShiro[i + 1] = cntShiro[i] + 1;
        }
    }

    long long ans = 1LL << 60;
    for (int i = 0; i <= N; i++) {
        long long temp = 0;
        // 黒石にする数
        temp += cntShiro[N] - cntShiro[i];
        // 白石にする数
        temp += cntKuro[i] - cntKuro[0];

        ans = min(ans, temp);
    }
    cout << ans;

    return 0;
}
