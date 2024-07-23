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

bool debug_flag = false;

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

    long long cnt = 0;
    for (int i = 0; i < S.length(); i++) {
        // cout << "i = " << i << endl;
        if (S[i] == 'U') {
            long long temp_up = 0;
            temp_up = S.length() - i - 1;
            long long temp_down = 0;
            temp_down = i * 2;
            logint2(temp_up, temp_down);
            cnt = cnt + temp_up + temp_down;
        }
        if (S[i] == 'D') {
            long long temp_up = 0;
            // temp_up = i * 2;
            temp_up = (S.length() - i - 1) * 2;
            long long temp_down = 0;
            // temp_down = S.length() - 1;
            temp_down = i;
            logint2(temp_up, temp_down);
            cnt = cnt + temp_up + temp_down;
        }
    }
    cout << cnt;

    return 0;
}
