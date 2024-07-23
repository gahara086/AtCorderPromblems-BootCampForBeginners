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
    long long K;
    cin >> K;

    // xxx Sが一文字の場合があるのに注意
    if (S.length() == 1) {
        long long ans = K / 2;
        cout << ans;

        return 0;
    }
    bool same_moji = true;

    for (int i = 0; i < S.length(); i++) {
        if (S[i] != S[0]) {
            same_moji = false;
            break;
        }
    }
    if (same_moji == true) {
        long long moji_num = S.length() * K;
        long long ans = moji_num / 2;
        cout << ans;
        return 0;
    }

    string calc_S = S;
    char prev = S[0];
    long long calc_ans = 0;
    for (int i = 1; i < calc_S.length(); i++) {
        if (calc_S[i] == prev) {
            calc_S[i] = '1';
        }
        prev = calc_S[i];
    }
    for (int i = 0; i < S.length(); i++) {
        if (calc_S[i] == '1') {
            calc_ans++;
        }
    }
    // cout << "calc_ans = " << calc_ans << endl;

    prev = S[0];
    S = S + S;
    // cout << "S = " << S << endl;
    for (int i = 1; i < S.length(); i++) {
        if (S[i] == prev) {
            S[i] = '1';
        }
        prev = S[i];
    }
    // cout << "S = " << S << endl;
    long long ans = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '1') {
            ans++;
        }
    }
    // cout << "S = " << S << endl;

    long long plus_1 = ans - calc_ans;
    long long result = calc_ans + (plus_1) * (K - 1);
    cout << result;

    // xxx Sが一文字の場合があるのに注意
    // char prev = S[0];
    // long long same_cnt = 0;
    // for (int i = 1; i < S.length(); i++) {
    //     if (S[i] == prev) {
    //         same_cnt++;
    //     }
    //     prev = S[i];
    // }
    // string calc_S = "";
    // for (int i = 0; i < K; i++) {
    //     calc_S += S;
    // }
    // S = calc_S;
    // // cout << "S = " << S << endl;
    // char prev = S[0];
    // for (int i = 1; i < S.length(); i++) {
    //     if (S[i] == prev) {
    //         S[i] = '1';
    //     }
    //     prev = S[i];
    // }
    // // cout << "S = " << S << endl;
    // long long ans = 0;
    // for (int i = 0; i < S.length(); i++) {
    //     if (S[i] == '1') {
    //         ans++;
    //     }
    // }
    // cout << "S = " << S << endl;
    // cout << ans;

    return 0;
}
