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

    long long cnt_A = 0;
    long long cnt_B = 0;
    long long cnt_C = 0;

    for (int i = 0; i < S.length(); i++) {
        if (S[i] == 'a') {
            cnt_A++;
        }
        if (S[i] == 'b') {
            cnt_B++;
        }
        if (S[i] == 'c') {
            cnt_C++;
        }
    }
    long long A_B = abs(cnt_A - cnt_B);
    long long A_C = abs(cnt_A - cnt_C);
    long long B_C = abs(cnt_B - cnt_C);
    long long sums = A_B + A_C + B_C;
    // logint3(A_B, A_C, B_C);
    // cout << "sums = " << sums << endl;
    if (A_B >= 2 || A_C >= 2 || B_C >= 2) {
        cout << "NO";
    } else {
        cout << "YES";
    }

    // long long max_cnt = cnt_A;
    // max_cnt = max(max_cnt, cnt_A);
    // max_cnt = max(max_cnt, cnt_B);
    // max_cnt = max(max_cnt, cnt_C);

    return 0;
}
