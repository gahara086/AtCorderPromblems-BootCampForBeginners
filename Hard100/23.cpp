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
    string S;
    cin >> S;
    reverse(S.begin(), S.end());

    // 後ろから判定していけば良さそう？？

    string dream = "dream";
    string dreamer = "dreamer";
    string erase = "erase";
    string eraser = "eraser";

    reverse(dream.begin(), dream.end());
    reverse(dreamer.begin(), dreamer.end());
    reverse(erase.begin(), erase.end());
    reverse(eraser.begin(), eraser.end());
    // cout << dream << endl;
    // cout << dreamer << endl;
    // cout << erase << endl;
    // cout << eraser << endl;

    int i = 0;
    long long cnt = 0;
    while (true) {
        if (i >= S.length()) {
            i = 0;
        }

        if (S[i] == dreamer[0] && S[i + 1] == dreamer[1] &&
            S[i + 2] == dreamer[2] && S[i + 3] == dreamer[3] &&
            S[i + 4] == dreamer[4] && S[i + 5] == dreamer[5] &&
            S[i + 6] == dreamer[6]) {
            S.erase(i, 7);
        }
        if (i >= S.length()) {
            i = 0;
        }
        if (S[i] == eraser[0] && S[i + 1] == eraser[1] &&
            S[i + 2] == eraser[2] && S[i + 3] == eraser[3] &&
            S[i + 4] == eraser[4] && S[i + 5] == eraser[5]) {
            S.erase(i, 6);
        }
        if (i >= S.length()) {
            i = 0;
        }
        // if (S[i] == dream[0] && S[i + 1] == dream[1] && S[i + 2] == dream[2]
        // &&
        //     S[i + 3] == dream[3] && S[i + 4] == dream[4]) {
        //     S.erase(i, 5);
        // }
        // if (i >= S.length()) {
        //     i = 0;
        // }
        // if (S[i] == erase[0] && S[i + 1] == erase[1] && S[i + 2] == erase[2]
        // &&
        //     S[i + 3] == erase[3] && S[i + 4] == erase[4]) {
        //     S.erase(i, 5);
        // }

        i++;
        if (i >= S.length()) {
            i = 0;
        }
        cnt++;
        if (cnt > 100000) {
            break;
        }
    }

    i = 0;
    cnt = 0;
    while (true) {
        if (i >= S.length()) {
            i = 0;
        }
        if (S[i] == dream[0] && S[i + 1] == dream[1] && S[i + 2] == dream[2] &&
            S[i + 3] == dream[3] && S[i + 4] == dream[4]) {
            S.erase(i, 5);
        }
        if (i >= S.length()) {
            i = 0;
        }
        if (S[i] == erase[0] && S[i + 1] == erase[1] && S[i + 2] == erase[2] &&
            S[i + 3] == erase[3] && S[i + 4] == erase[4]) {
            S.erase(i, 5);
        }
        i++;
        cnt++;
        if (cnt > 100000) {
            break;
        }
    }

    if (S.length() == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
