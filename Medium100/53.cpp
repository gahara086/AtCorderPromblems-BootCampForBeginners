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
    long long N;
    cin >> N;

    long long A[N + 2];
    vector<long long> A_v;
    long long sum = 0;
    long long pos = 0;
    A[0] = 0;      // start
    A[N + 1] = 0;  // goal
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        A_v.push_back(A[i]);

        long long distance = abs(pos - A[i]);
        sum += distance;

        pos = A[i];
        // cout << sum << endl;
        if (i == N) {
            sum += abs(A[i]);
            // cout << "total = " << sum << endl;
        }
    }

    // long long ans[N + 1];
    for (int i = 1; i <= N; i++) {
        long long pos_a = A[i - 1];
        long long pos_b = A[i];
        long long pos_c = A[i + 1];
        long long calc =
            -abs(pos_a - pos_b) - abs(pos_b - pos_c) + abs(pos_c - pos_a);

        long long ans = sum + calc;
        // long long ans = sum - distance;
        cout << ans << ' ';
    }

    return 0;
}
