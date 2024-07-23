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

    if (S == "zyxwvutsrqponmlkjihgfedcba") {
        int ans = -1;
        cout << ans;
        return 0;
    }

    map<char, bool> jisyo;
    for (int i = 'a'; i <= 'z'; i++) {
        jisyo[(char)i] = false;
    }
    // for debug
    auto begin = jisyo.begin();
    auto end = jisyo.end();
    for (auto iter = begin; iter != end; iter++) {
        // cout << iter->first << endl;
        // cout << iter->second << endl;
    }

    for (int i = 0; i < S.length(); i++) {
        jisyo[S[i]] = true;
    }

    bool all = true;
    char setmoji;
    for (auto iter = begin; iter != end; iter++) {
        // cout << iter->first << endl;
        // cout << iter->second << endl;
        if (iter->second == false) {
            setmoji = iter->first;
            all = false;
            break;
        }
    }

    if (all == false) {
        S = S + setmoji;
    } else if (all == true) {
        int A = 'a';
        int insert_moji;
        int wrong;
        for (int i = 0; i < S.length(); i++) {
            if (char(A) == S[i]) {
                A++;
            } else {
                insert_moji = A;
                wrong = i;
            }
        }
        S.erase(wrong - 2);
        S = S + (char)insert_moji;
    }
    cout << S;

    return 0;
}
