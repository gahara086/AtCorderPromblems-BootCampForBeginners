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
const long long MOD = 1e+09 + 7;
int main() {
    long long X;
    cin >> X;
    long long Y;
    cin >> Y;

    long long cnt_X;
    cnt_X = X / 2;
    long long pos_x;
    long long pos_y;
    pos_x = cnt_X * 2;
    pos_y = cnt_X;
    // 解き方は合ってる combの求め方がおかしい

    if ((Y - pos_y) % 2 == 1) {
        cout << 0;
        return 0;
    }
    long long cnt_Y;
    cnt_Y = (Y - pos_y) / 2;

    cout << cnt_X << ":" << cnt_Y << endl;
    long long num = cnt_X + cnt_Y;
    long long ans = 1;
    long long j = cnt_X;
    for (int i = num; i > num - cnt_X; i--) {
        ans = ans * num % MOD;
        ans = ans / j;
        j--;
    }
    for (int i = cnt_X; i > 0; i--) {
        // ans = ans / i;
    }
    // cout << ans;
    // long long test = comb(num, 1);
    // cout << comb(num, cnt_X);

    return 0;
}
