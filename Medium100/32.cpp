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
    long long Y;
    cin >> Y;

    long long ans_10000 = -1;
    long long ans_5000 = -1;
    long long ans_1000 = -1;

    for (int i = 0; i <= N; i++) {
        int sum = 0;
        sum += i * 10000;
        for (int j = 0; j <= N - i; j++) {
            sum += j * 5000;
            if (Y - (N - i - j) * 1000 == sum) {
                ans_10000 = i;
                ans_5000 = j;
                ans_1000 = (N - i - j);
            }

            if (ans_10000 != -1) {
                break;
            } else {
                sum -= j * 5000;
            }
        }
        if (ans_10000 != -1) {
            break;
        }
    }

    cout << ans_10000 << ' ' << ans_5000 << ' ' << ans_1000;

    return 0;
}
