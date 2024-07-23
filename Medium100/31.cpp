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
    long long A[N + 1];
    vector<long long> A_vector;
    for (int n = 1; n <= N; n++) {
        cin >> A[n];
        A_vector.push_back(A[n]);
    }

    long long cnt_2 = 0;
    long long cnt_4 = 0;

    for (int n = 1; n <= N; n++) {
        if (A[n] % 2 == 0) {
            cnt_2++;
        }
        if (A[n] % 4 == 0) {
            cnt_2--;
            cnt_4++;
        }
    }
    long long calc_ans = 0;
    calc_ans = cnt_4 * 2 + (cnt_2 / 2) * 2 + 1;
    // cout << calc_ans << endl;
    if (calc_ans >= N) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
