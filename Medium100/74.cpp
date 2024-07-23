﻿#include <bits/stdc++.h>

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
    // int N;
    long long N;
    cin >> N;

    // int A[N+1];
    string A[N + 1];
    vector<string> A_v;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A_v.push_back(A[i]);
    }

    map<char, int> cnt[N + 1];  // 各文字列の文字数のカウント用
    map<char, int> cnt_moji;    // 全ての文字の最小数の計算用
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < A[i].length(); j++) {
            cnt[i][A[i][j]] = 0;
            cnt_moji[A[i][j]] = 9999999;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < A[i].length(); j++) {
            cnt[i][A[i][j]]++;
        }
    }

    auto begin = cnt_moji.begin();
    auto end = cnt_moji.end();
    for (auto iter = begin; iter != end; iter++) {
        // cout << iter->first << endl;
        for (int i = 0; i < N; i++) {
            // for (int j = 0; j < A[i].length(); j++) {
            // cnt[i][A[i][j]]++;
            // cnt_moji[A[i][j]] = min(cnt_moji[A[i][j]], cnt[i][A[i][j]]);
            cnt_moji[iter->first] =
                min(cnt_moji[iter->first], cnt[i][iter->first]);
            // }
        }
    }

    string ans = "";
    for (auto iter = begin; iter != end; iter++) {
        // cout << iter->first << " = ";
        // cout << iter->second << endl;
        for (int i = 0; i < iter->second; i++) {
            ans += iter->first;
        }
    }
    cout << ans;

    return 0;
}