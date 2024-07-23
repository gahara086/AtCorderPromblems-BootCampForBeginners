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
    long long Q;
    cin >> Q;

    long long l[Q + 1];
    long long r[Q + 1];
    for (int i = 0; i < Q; i++) {
        cin >> l[i];
        cin >> r[i];
    }

    int MAX = 100000, times = 0, cnt = 0;
    // int MAX = 15, times = 0, cnt = 0;
    map<int, bool> sosuu;
    map<int, int> sosuu_cnt;
    for (int i = 0; i <= MAX; i++) {
        sosuu[i] = false;
        sosuu_cnt[i] = 0;
    }

    for (int i = 2; i <= MAX; i++) {
        bool isPrime = true;
        for (int j = 2; j <= sqrt(i); j++) {
            times++;
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            // cout << i << " ";
            cnt++;
            sosuu[i] = true;
        }
        sosuu_cnt[i] = sosuu_cnt[i - 1];
        if (sosuu[i] == true) {
            // if ((i + 1) % 2 == 1) {
            if (sosuu[(i + 1) / 2]) {
                sosuu_cnt[i]++;
            }
            // }
        }
    }
    // for (int i = 2; i <= MAX; i++) {
    //     cout << "i = " << i << endl;
    //     cout << sosuu_cnt[i] << ' ' << endl;
    // }

    for (int i = 0; i < Q; i++) {
        int ans;
        ans = sosuu_cnt[r[i]] - sosuu_cnt[(l[i] - 1)];
        cout << ans << endl;
    }

    return 0;
}
