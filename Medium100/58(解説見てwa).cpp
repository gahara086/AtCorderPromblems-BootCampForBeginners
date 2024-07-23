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
    long long A, B, C, D;
    cin >> A >> B >> C >> D;

    string S;
    cin >> S;

    // for (int i = 0; i < N; i++) {
    //     if (S[i] == '#' && S[i + 1] == '#') {
    //         cout << "No";
    //         return 0;
    //     }
    // }

    bool ans = true;
    if (D > C) {
        for (int i = A - 1; i < D; i++) {
            if (S[i] == '#' && S[i + 1] == '#') {
                ans = false;
                break;
            }
        }
        if (ans) {
            cout << "Yes";
        } else {
            cout << "No";
        }
        return 0;
    }

    ans = false;
    int spase_cnt = 0;
    if (D < C) {
        for (int i = A - 1; i < D; i++) {
            if (S[i] == '#' && S[i + 1] == '#') {
                cout << "No";
                return 0;
            }
        }
        for (int i = B - 1; i < D; i++) {
            if (S[i] == '#' && S[i + 1] == '#') {
                cout << "No";
                return 0;
            }
            if (spase_cnt >= 3) {
                // cout << "i = " << i;
                ans = true;
                break;
            }
            if (S[i] == '#') {
                spase_cnt = 0;
            } else {
                spase_cnt++;
            }
            if (spase_cnt >= 3) {
                // cout << "i = " << i;
                ans = true;
                break;
            }
        }
    }
    if (ans) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
