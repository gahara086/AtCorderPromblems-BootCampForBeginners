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
    long long L;
    cin >> L;
    long long R;
    cin >> R;
    long long min_LR = L * (L + 1);
    long long max_LR = R * (R - 1);

    const long long mod = 2019;
    const long long mod_max = 2019 * 2019;

    long long ans = 999999;
    long long cnt = 0;

    long long min_L = 9999999;
    bool flag = false;
    for (int i = L; i < R; i++) {
        for (int j = i + 1; j <= R; j++) {
            long long temp_ans = i * j % mod;
            if (temp_ans < 0) {
                temp_ans += mod;
            }
            logint2(i, j);
            logint1(temp_ans);

            ans = min(ans, temp_ans);
            if (temp_ans == 0) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

    // ans = min_L * (min_L + 1);
    // for (int i = L; i < R; i++) {
    //     for (int j = i + 1; j <= R; j++) {
    //         if (cnt > mod_max) {
    //             break;
    //         }

    //         long long to_mod = i * j;

    //         ans = min(ans, to_mod % mod);

    //         cnt++;
    //     }
    //     if (cnt > mod_max) {
    //         break;
    //     }
    // }
    cout << ans;

    return 0;
}
