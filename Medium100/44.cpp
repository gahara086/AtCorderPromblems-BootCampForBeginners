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

int main() {
    // int N;
    long long N;
    cin >> N;

    long long A[N + 1];
    vector<long long> A_v;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        A_v.push_back(A[i]);
    }

    long long B[N + 1];
    long long cnt = 0;
    for (int i = 1; i <= N; i++) {
        cout << "A[N - i + 1] = " << A[N - i + 1] << endl;
        if (cnt % 2 == 0) {
            B[i] = A[N - i + 1];
            cout << "i = " << i << endl;
        } else {
            // B[N - i + 1] = A[N - i + 1];
            // cout << "N - i + 1 = " << N - i + 1 << endl;
        }

        // cout << cnt << endl;
        cnt++;
    }
    for (int i = 1; i <= N; i++) {
        cout << B[i] << ' ';
    }

    // vector<long long> B;
    // for (int i = 1; i <= N; i++) {
    //     B.push_back(A[i]);
    //     reverse(B.begin(), B.end());
    // }

    // for (int i = 0; i < N; i++) {
    //     cout << B[i] << ' ';
    // }
    return 0;
}
