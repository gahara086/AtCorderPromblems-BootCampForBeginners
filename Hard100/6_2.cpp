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
    string S;
    cin >> S;
    string T;
    cin >> T;

    int N_S = S.length();
    int N_T = T.length();
    // logint2(N_S, N_T);
    string temp_ans = S;

    bool ok2 = false;
    for (int i = N_S - 1; i >= 0; i--) {
        if (S[i] == T[0]) {
            bool ok = true;
            for (int j = 0; j < N_T; j++) {
                // cout << "S[i - j]   = " << S[i + j] << endl;
                // cout << "T[N_T - j] = " << T[j] << endl;
                if (S[i + j] == '?') {
                    continue;
                }
                if (S[i + j] != T[j]) {
                    ok = false;
                    break;
                }
            }

            if (ok == true) {
                ok2 = true;
                for (int j = 0; j < N_T; j++) {
                    if (S[i + j] == '?') {
                        S[i + j] = T[j];
                    }
                }
            }
        }

        if (ok2 == true) {
            for (int i = 0; i < N_S; i++) {
                if (S[i] == '?') {
                    S[i] = 'a';
                }
            }
            cout << S;
            return 0;

            // break;
        }
        if (S[i] == T[N_T - 1]) {
            bool ok = true;
            for (int j = 0; j < N_T; j++) {
                // cout << "i - j    = " << i - j << endl;
                // cout << "S[i - j] = " << S[i - j] << endl;
                // cout << "T[N_T - 1 - j] = " << T[N_T - 1 - j] << endl;
                if (S[i - j] == '?') {
                    continue;
                }
                if (S[i - j] != T[N_T - 1 - j]) {
                    ok = false;
                    break;
                }
            }
            // for (int j = N_T - 1; j >= 0; j--) {
            //     cout << N_T - j + 1 << endl;
            //     if (S[i + N_T - j] == '?') {
            //         continue;
            //     }
            //     if (S[i + N_T - j] != T[j]) {
            //         ok = false;
            //         break;
            //     }
            // }
            if (ok == true) {
                ok2 = true;
                for (int j = 0; j < N_T; j++) {
                    if (S[i - j] == '?') {
                        S[i - j] = T[N_T - 1 - j];
                    }
                }
            }
        }
        if (ok2 == true) {
            cout << S << endl;
            for (int i = 0; i < N_S; i++) {
                if (S[i] == '?') {
                    S[i] = 'a';
                }
            }
            cout << S;
            return 0;

            // break;
        }
    }
    cout << "UNRESTORABLE ";

    return 0;
}