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
long long gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}
unsigned GetDigit(unsigned num) {
    unsigned digit = 0;
    while (num != 0) {
        num /= 10;
        digit++;
    }
    return digit;
}

vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end());  // 昇順に並べる
    return ret;
}

int main() {
    // int N;
    long long N;
    cin >> N;

    // ごちゃごちゃせずにNの約数を列挙すればOK
    long long ans = GetDigit(N);
    vector<long long> div_all = divisor(N);
    for (int i = 0; i < div_all.size(); i++) {
        long long div = N / div_all[i];
        long long div_digit = GetDigit(div);
        long long i_digit = GetDigit(div_all[i]);
        long long max_digit = max(div_digit, i_digit);
        ans = min(ans, max_digit);
    }

    // long long ans = GetDigit(N);
    // for (long long i = 1; i <= N / 2; i++) {
    //     if (N % i == 0) {
    //         long long div = N / i;
    //         long long div_digit = GetDigit(div);
    //         long long i_digit = GetDigit(i);
    //         long long max_digit = max(div_digit, i_digit);
    //         ans = min(ans, max_digit);
    //     }
    // }
    cout << ans;

    return 0;
}
