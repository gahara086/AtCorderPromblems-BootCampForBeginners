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
    int K;
    cin >> K;

    int A[N + 1];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int left = A[0];
    int right = A[K - 1];
    int dis = abs(left) + abs(right - left);

    for (int i = K; i < N; i++) {
        int temp_left = A[i - K];
        int temp_right = A[i - K + K - 1];
        int temp_dis = abs(temp_left) + abs(temp_right - temp_left);
        dis = min(dis, temp_dis);
        // cout << "temp_left  = " << temp_left << endl;
        // cout << "temp_right = " << temp_right << endl;
        // cout << "temp_dis   = " << temp_dis << endl;
    }

    for (int i = N - 1; i >= K - 1; i--) {
        int temp_left = A[i - K + 1];
        int temp_right = A[i];
        int temp_dis = abs(temp_right) + abs(temp_right - temp_left);
        dis = min(dis, temp_dis);
        // cout << "temp_left  = " << temp_left << endl;
        // cout << "temp_right = " << temp_right << endl;
        // cout << "temp_dis   = " << temp_dis << endl;
    }

    cout << dis;

    return 0;
}
