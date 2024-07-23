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
    // int N;
    long long N;
    cin >> N;
    // int M;
    long long M;
    cin >> M;
    // int H;
    long long H;
    cin >> H;
    // int W;
    long long W;
    cin >> W;

    // int A;
    // long long A;
    // cin >> A;
    // int B;
    // long long B;
    // cin >>B;

    // string S;
    long long S;
    cin >> S;

    long long K;
    cin >> K;

    // int A[N+1];
    long long A[N + 1];
    vector<long long> A_v;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A_v.push_back(A[i]);
    }
    // for (int i = 1; i <= N; i++) {
    //     cin >> A[i];
    //     A_v.push_back(A[i]);
    // }
    // int A[H + 1][W + 1];
    // for (int i = 1; i <= H; i++) {
    //     for (int j = 1; j <= W; j++) {
    //         cin >> A[i][j];
    //     }
    // }

    long long B[N + 1];
    vector<long long> B_v;
    for (int i = 0; i < N; i++) {
        cin >> B[i];
        B_v.push_back(B[i]);
    }
    // for (int i = 1; i <= N; i++) {
    //     cin >> B[i];
    //     B_v.push_back(B[i]);
    // }

    long long P[N + 1];
    vector<long long> P_v;
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
        P_v.push_back(P[i]);
    }

    // long long W[N + 1];
    // for (long long n = 1; n <= N; n++) {
    //     cin >> W[n];
    // }
    // long long V[N + 1];
    // for (long long n = 1; n <= N; n++) {
    //     cin >> V[n];
    // }

    return 0;
}
