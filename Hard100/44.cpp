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
int counter(int x) {
    if (x == 0) return 0;
    return counter(x >> 1) + (x & 1);
}
int main() {
    long long N;
    cin >> N;

    long long A[N + 1];
    vector<long long> x[N + 1];
    vector<long long> y[N + 1];

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        for (int j = 0; j < A[i]; j++) {
            long long temp;
            cin >> temp;
            x[i].push_back(temp);
            cin >> temp;
            y[i].push_back(temp);
        }
    }

    // 1 <= N <= 15なので、全パターンを総当たりで計算する
    // 2 ^ 15でOK
    int ans = 0;

    // for (long long i = pow(2, N) - 1; i >= 0; i--) {
    //     bool flag = true;
    //     bool ok = true;
    //     for (int j = 1; j <= N; j++) {
    //         int temp = i >> j;
    //         int hantei = temp && 1;

    //         for (int k = 1; k <= N; k++) {
    //             for (int l = 0; l < A[k]; l++) {
    //                 if (((hantei >> (x[i][j] - 1)) & 1) ^ y[i][j]) ok =
    //                 false;
    //             }
    //         }
    //     }
    //     if (ok) ans = max(ans, counter(bits));
    // }

    return 0;
}
