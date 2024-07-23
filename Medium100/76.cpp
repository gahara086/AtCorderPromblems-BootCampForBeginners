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
    string S;
    cin >> S;

    long long ans = 1000000000000000000LL;
    long long cnt_E = 0;
    long long cnt_W = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'E') {
            cnt_E++;
        }
        if (S[i] == 'W') {
            cnt_W++;
        }
    }

    long long cnt_now_E = 0;
    long long cnt_now_W = 0;
    for (int i = 0; i < N; i++) {
        long long temp_ans = 0;
        long long calc_E = 0;
        if (S[i] == 'E') {
            calc_E = cnt_E - cnt_now_E - 1;
        } else {
            calc_E = cnt_E - cnt_now_E;
        }
        long long calc_W = cnt_now_W;
        // for debug
        // cout << "-------------------" << endl;
        // cout << "i      = " << i << endl;
        // cout << "calc_E = " << calc_E << endl;
        // cout << "calc_W = " << calc_W << endl;
        temp_ans = calc_E + calc_W;

        ans = min(ans, temp_ans);
        if (S[i] == 'E') {
            cnt_now_E++;
        }
        if (S[i] == 'W') {
            cnt_now_W++;
        }
    }

    cout << ans;

    return 0;
}
