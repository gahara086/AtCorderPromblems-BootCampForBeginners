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
    int N;
    cin >> N;

    int A[N + 1];
    vector<long long> A_v;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A, A + N);
    for (int i = 0; i < N; i++) {
        // cout << "A[i] = " << A[i] << endl;
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int size = A[i];
        for (int j = 0; j < N; j++) {
            // if (j == N - 1) {
            // if (A[j] < size * 2) {
            if (A[N - 1] < size * 2) {
                cnt++;
                break;
            } else {
            }
            // }
            if (i == j) {
                continue;
            }
            // if (size >= A[j] * 2) {
            if (size >= A[j] * 2) {
                size += A[j];
                // if (A[j] == A[N - 1]) {
                //     cnt++;
                // }
            } else if (A[j] == size * 2) {
                size += A[j];
            } else {
                // cout << "j = " << j << endl;
                // cout << "A[j] = " << A[j] << endl;
            }
        }
        // if (size >= A[N - 1] * 2) {
        // } else {
        // cout << "size = " << size << endl;
        //     cnt++;
        // }
    }
    cout << cnt;

    return 0;
}
