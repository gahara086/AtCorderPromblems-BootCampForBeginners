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

    long long left = 0;
    long long right = 10000000;

    long long sum = (1 + N) * N / 2;
    bool ans[N + 1];
    for (int i = 0; i < N; i++) {
        ans[i] = true;
    }

    long long minus = N;
    while (true) {
        // cout << "sum = " << sum << endl;
        // cout << "minus = " << minus << endl;
        if (sum == N) {
            break;
        }
        long long temp_sum = sum - minus;
        // cout << "temp_sum = " << temp_sum << endl;
        if (temp_sum >= N) {
            ans[minus] = false;
            sum = temp_sum;
        }
        if (temp_sum == N) {
            break;
        }
        minus--;
        if (minus == 0) {
            break;
        }
    }
    for (int i = 1; i <= N; i++) {
        if (ans[i] == true) {
            cout << i << endl;
        }
    }

    return 0;
}
