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

void logint1(long long n) {
    if (debug_flag) cout << "arg_1 = " << n << endl;
}
void logint2(long long n, long long m) {
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

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}
/*  lcm (a, b) : 2整数版
    入力：整数 a, b
    出力：aとbの最小公倍数
*/
long long lcm(long long a, long long b) {
    long long d = gcd(a, b);
    return a / d * b;
}

int main() {
    long long a;
    cin >> a;
    long long b;
    cin >> b;
    long long x;
    cin >> x;

    long long lcm_ab = (a, b);

    long long cnt_a = a / x;
    long long cnt_b = b / x;

    long long cnt_a_lcm = a / lcm_ab;
    long long cnt_b_lcm = b / lcm_ab;

    long long result_lcm = cnt_b_lcm - cnt_a_lcm;
    long long result_ab = cnt_b - cnt_a;
    if (a % x == 0) {
        result_ab++;
    }

    // logint2(result_lcm, result_ab);
    long long result = result_lcm + result_ab;
    // cout << result;
    cout << result_ab;

    return 0;
}
