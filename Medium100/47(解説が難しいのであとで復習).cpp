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

int facctorialMethod(int k) {
    int sum = 1;
    for (int i = 1; i <= k; ++i) {
        sum *= i;
    }
    return sum;
}

int main() {
    int N;
    cin >> N;
    int P;
    cin >> P;

    long long A[N + 1];
    vector<long long> A_v;
    long long odd = 0;
    long long even = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        A_v.push_back(A[i]);
        if (A[i] % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
    long long cnt = 0;
    long long odd_cnt = 0;
    long long evnn_cnt = 0;
    if (P == 0) {
        if (odd > 0) {
            cnt = pow(2, N - 1);
        } else {
            cnt = pow(2, N);
        }
    }
    if (P == 1) {
        if (odd > 0) {
            cnt = pow(2, N - 1);
        } else {
            cnt = 0;
        }
    }
    cout << cnt;

    return 0;
}
