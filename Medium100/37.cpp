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
    // input
    int N;
    cin >> N;
    int A[N + 1];
    int max_A = -1;
    vector<long long> A_vector;
    for (int n = 1; n <= N; n++) {
        cin >> A[n];
        max_A = max(max_A, A[n]);
        A_vector.push_back(A[n]);
    }

    // calc
    long long cnt = 0;
    if (A[1] > 0) {
        // cnt++;
    }
    for (int i = 0; i < max_A; i++) {
        int prev_A = 0;
        for (int n = 1; n <= N; n++) {
            if (A[n] > 0 && prev_A > 0) {
            } else {
                if (A[n] > 0 && prev_A == 0) {
                    cnt++;
                }
            }
            prev_A = A[n];
            if (A[n] - 1 >= 0) {
                A[n]--;
            }
        }
    }

    // ans
    cout << cnt;

    return 0;
}
