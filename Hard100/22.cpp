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

    string T;
    cin >> T;

    int N = S.length();

    bool hikaku[50][50];
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            hikaku[i][j] = false;
        }
    }

    for (int i = 0; i < N; i++) {
        int S_moji = S[i] - 'a';
        int T_moji = T[i] - 'a';
        hikaku[S_moji][T_moji] = true;
    }

    for (int i = 0; i < 50; i++) {
        int cnt = 0;
        for (int j = 0; j < 50; j++) {
            if (hikaku[i][j]) {
                cnt++;
            }
        }
        if (cnt > 1) {
            cout << "No";
            return 0;
        }
    }

    for (int j = 0; j < 50; j++) {
        int cnt = 0;
        for (int i = 0; i < 50; i++) {
            if (hikaku[i][j]) {
                cnt++;
            }
        }
        if (cnt > 1) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";

    return 0;
}
