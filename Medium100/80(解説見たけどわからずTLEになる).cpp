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
    string S;
    cin >> S;

    map<string, long long> cnt;
    long long MAX = pow(2, N);
    for (long long i = MAX - 1; i > 0; i--) {
        long long temp_i = i;
        string temp_str = "";
        for (long long j = 0; j < N; j++) {
            if (temp_i & 1 == 1) {
                temp_str = temp_str + S[j];
            }
            temp_i = temp_i >> 1;
        }
        // cnt[temp_str] = true;
        cnt[temp_str]++;
    }

    auto begin = cnt.begin();
    auto end = cnt.end();
    long long ans = 0;
    for (auto iter = begin; iter != end; iter++) {
        // cout << iter->first << endl;
        // cout << iter->first.length() << endl;
        if (iter->first.length() == 0) {
            continue;
        }
        for (int i = 0; i < iter->first.length() - 1; i++) {
            for (int j = i + 1; j < iter->first.length(); j++) {
                if (iter->first[i] == iter->first[j]) {
                    iter->second = 0;
                    break;
                }
            }
            if (iter->second == 0) {
                break;
            }
        }
        // cout << iter->second << endl;
        ans += iter->second;
    }
    cout << ans;

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         string temp;
    //         temp = S[j];
    //         for (int k = j + 1; k < N; k++) {
    //             string temp_2 = temp;
    //         }
    //     }
    // }

    return 0;
}
