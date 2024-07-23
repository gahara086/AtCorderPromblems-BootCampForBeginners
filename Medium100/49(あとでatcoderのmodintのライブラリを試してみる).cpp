﻿#include <bits/stdc++.h>

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

int main() {
    long long N;
    cin >> N;
    // long long A[N + 1];
    long long temp;
    vector<long long> A_v;
    long long temp_max = -1;
    for (int i = 1; i <= N; i++) {
        // cin >> A[i];
        // A_v.push_back(A[i]);
        cin >> temp;
        A_v.push_back(temp);
    }
    sort(A_v.begin(), A_v.end());

    long long max_1 = -1;
    long long max_2 = -1;
    long long prev = A_v[0];
    bool first_take = true;
    for (int i = 1; i < N; i++) {
        // logint1(A_v[i]);
        // if (prev == A_v[i] && first_take) {
        //     max_1 = A_v[i];
        //     first_take = false;
        // } else
        if (prev == A_v[i] && A_v[i] != max_1) {
            // cout << "prev = " << prev << endl;
            max_2 = max_1;
            max_1 = A_v[i];
        }
        prev = A_v[i];
    }
    // logint2(max_1, max_2);
    long long ans = max_1 * max_2;
    if (max_1 < 0 || max_2 < 0) {
        ans = 0;
    }
    cout << ans;

    return 0;
}
