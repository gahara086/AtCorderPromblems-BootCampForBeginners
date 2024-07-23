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
    string temp_ans = S;

    // calc
    // 辞書順なので可能な限り先頭から'a'で埋める必要がある
    // 後方から貪欲的に一致する文字列を探していく
    // トライアンドエラーでWAの数が同じだったのは、前方から貪欲法をしていたからっぽい
    bool ans = false;
    for (int i = 0; i < N_S; i++) {
        if (S[i] == '?') {
            continue;
        }
        // cout << "S[i] = " << S[i] << endl;
        // cout << "T[N_T - 1] = " << T[N_T - 1] << endl;
        if (S[i] == T[N_T - 1]) {
            // if (i + N_T >= N_S) {
            // continue;
            bool same_bak = true;
            for (int j = N_T - 1; j >= 0; j--) {
                // cout << "S[i - j] = " << S[i - j] << endl;
                // cout << "T[j]     = " << T[N_T - j - 1] << endl;
                if (S[i - j] == '?') {
                    continue;
                }
                if (S[i - j] != T[N_T - j - 1]) {
                    same_bak = false;
                }
            }
            // cout << "same_bak = " << same_bak << endl;
            if (same_bak == true) {
                ans = true;
                for (int j = N_T - 1; j >= 0; j--) {
                    if (S[i - j] == '?') {
                        // S[i - j] = T[j];
                        temp_ans[i - j] = T[N_T - j - 1];
                    }
                }
                // for (int k = 0; k < N_S; k++) {
                //     if (S[k] == '?') {
                //         S[k] = 'a';
                //     }
                // }
                // break;
                // }
            }
        }
        if (S[i] == T[0]) {
            if (i + N_T > N_S) {
                // continue;
            }
            bool same = true;
            for (int j = 0; j < N_T; j++) {
                if (S[i + j] == '?') {
                    continue;
                }
                if (S[i + j] != T[j]) {
                    same = false;
                }
            }

            if (same == true) {
                ans = true;
                for (int j = 0; j < N_T; j++) {
                    if (S[i + j] == '?') {
                        // S[i + j] = T[j];
                        temp_ans[i + j] = T[j];
                    }
                }
                // for (int k = 0; k < N_S; k++) {
                //     if (S[k] == '?') {
                //         S[k] = 'a';
                //     }
                // }
                // break;
            }

            bool same_bak = true;
            for (int j = N_T - 1; j >= 0; j--) {
                if (S[i - j] == '?') {
                    continue;
                }
                if (S[i - j] != T[j]) {
                    same_bak = false;
                }
            }
            if (same_bak == true) {
                ans = true;
                for (int j = N_T - 1; j >= 0; j--) {
                    if (S[i - j] == '?') {
                        // S[i - j] = T[j];
                        // temp_ans[i - j] = T[j];
                    }
                }
                // for (int k = 0; k < N_S; k++) {
                //     if (S[k] == '?') {
                //         S[k] = 'a';
                //     }
                // }
                // break;
            }
        }
    }
    for (int k = 0; k < N_S; k++) {
        if (temp_ans[k] == '?') {
            temp_ans[k] = 'a';
        }
    }
    if (ans == true) {
        // cout << S;
        cout << temp_ans;
    } else {
        cout << "UNRESTORABLE";
    }

    return 0;
}
