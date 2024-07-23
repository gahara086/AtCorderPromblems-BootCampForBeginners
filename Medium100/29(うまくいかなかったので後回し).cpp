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
    string s, t;
    cin >> s;
    cin >> t;
    vector<char> S;
    vector<char> T;

    for (int i = 0; i < s.length(); i++) {
        S.push_back(s[i]);
    }
    for (int i = 0; i < t.length(); i++) {
        T.push_back(t[i]);
    }
    // cout << S[0] << S[1] << endl;
    // cout << T[0] << T[1] << endl;
    sort(S.begin(), S.end());
    sort(T.begin(), T.end(), greater<int>());
    // cout << S[0] << S[1] << endl;
    // cout << T[0] << T[1] << endl;

    int length_min = min(s.length(), t.length());
    int length_max = max(s.length(), t.length());

    long long calc_S[100];
    long long calc_T[100];
    for (int i = 0; i < 100; i++) {
        calc_S[i] = 0;
        calc_T[i] = 0;
    }
    for (int i = 0; i < length_max; i++) {
        *calc_S = *calc_S << 4;
        if (i < s.length()) {
            *calc_S += (long long)S[i];
        }

        *calc_T = *calc_T << 4;
        if (i < t.length()) {
            *calc_T += (long long)T[i];
        }
    }
    cout << *calc_S << endl;
    cout << *calc_T << endl;
    // cout << "calc_S = " << hex << calc_S << endl;
    // cout << "calc_T = " << hex << calc_T << endl;
    bool ans = true;
    if (*calc_S < *calc_T) {
        ans = true;
    } else {
        ans = false;
    }
    if (ans) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    // bool long_is_S = (length_max == s.length()) ? true : false;
    // for (int i = 0; i < length_max; i++) {
    //     if (i > length_min) {
    //         if (long_is_S) {
    //             if (S[length_min] == T[length_min]) {
    //                 // ans = false;
    //                 // break;
    //             }
    //         } else {
    //             continue;
    //         }
    //     }
    //     if (i == length_min) {
    //         if (length_min == length_max) {
    //             if (S[i] == T[i]) {
    //                 ans = false;
    //             }
    //         }
    //     }
    //     if (i < length_min) {
    //         if (S[i] >= T[i]) {
    //         } else {
    //             cout << S[i] << endl;
    //             cout << T[i] << endl;
    //             cout << "hoge" << endl;
    //             ans = false;
    //             break;
    //         }
    //     }
    // }
    // if (ans) {
    //     cout << "Yes";
    // } else {
    //     cout << "No";
    // }

    return 0;
}
