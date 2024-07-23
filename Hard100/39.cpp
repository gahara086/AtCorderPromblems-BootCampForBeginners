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
    long long N;
    cin >> N;
    string S;
    cin >> S;

    long long cnt_sakaime = N;
    for (int i = 0; i < N; i++) {
        if (S[i] == '#') {
            cnt_sakaime = i;
            break;
        }
    }
    long long cntKuro = N;
    for (int i = cnt_sakaime; i < N; i++) {
        if (i == cnt_sakaime) {
            cntKuro = 0;
        }
        if (S[i] == '.') {
            cntKuro++;
        }
    }

    cnt_sakaime = -1;
    for (int i = N - 1; i >= 0; i--) {
        if (S[i] == '.') {
            cnt_sakaime = i;
            break;
        }
    }
    long long cntShiro = N;
    for (int i = cnt_sakaime; i >= 0; i--) {
        if (i == cnt_sakaime) {
            cntShiro = 0;
        }
        if (S[i] == '#') {
            cntShiro++;
        }
    }

    // cout << "cntKuro  = " << cntKuro << endl;
    // cout << "cntShiro = " << cntShiro << endl;

    long long ans = min(cntKuro, cntShiro);
    cout << ans;

    return 0;
}
