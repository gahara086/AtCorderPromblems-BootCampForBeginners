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
// 素因数分解
template <typename T>
map<T, T> prime_factor(T n) {
    map<T, T> ret;
    for (T i = 2; i * i <= n; i++) {
        T tmp = 0;
        while (n % i == 0) {
            tmp++;
            n /= i;
        }
        ret[i] = tmp;
    }
    if (n != 1) ret[n] = 1;
    return ret;
}
/*  divisor_num(n)
    入力：整数 n
    出力：nの約数の個数
    計算量：O(√n)
*/
template <typename T>
T divisor_num(T N) {
    map<T, T> pf = prime_factor(N);
    T ret = 1;
    for (auto p : pf) {
        ret *= (p.second + 1);
    }
    return ret;
}

int main() {
    // int N;
    long long N;
    cin >> N;

    if (N == 1) {
        cout << 1;
        return 0;
    }

    map<long long, long long> div;
    for (int i = 1; i <= N; i++) {
        // div[i] = 1;
        div[i] = 0;
    }
    div[0] = 0;
    div[1] = 1;

    // for (int i = 1; i <= N; i++) {
    //     cout << "i: " << i << " div_num: " << divisor_num(i) << endl;
    // }
    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= i; j++) {
            long long temp = 0;
            long long temp_i = i;
            while (temp_i % j == 0) {
                temp++;
                temp_i = temp_i / j;
            }
            div[j] += temp;
        }
    }
    long long ans = 1;
    const long long MOD = 1000000000 + 7;
    for (int i = 2; i <= N; i++) {
        // cout << "i: " << i << " div: " << div[i] << endl;
        long long cnt = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                cnt++;
            }
            if (cnt >= 2) {
                break;
            }
        }
        if (cnt == 1) {
            // cout << "i: " << i << " div: " << div[i] << endl;
            ans = ans * (div[i] + 1) % MOD;
        }
    }
    cout << ans;

    return 0;
}
