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
template <class T>
bool contain(const std::string& s, const T& v) {
    return s.find(v) != std::string::npos;
}
int main() {
    long long N;
    cin >> N;
    string A[N + 1];
    pair<bool, bool> moji[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i][0] == 'B') {
            moji[i].first = true;
        } else {
            moji[i].first = false;
        }
        int temp = A[i].length();
        if (A[i][temp - 1] == 'A') {
            moji[i].second = true;
        } else {
            moji[i].second = false;
        }
    }
    int AB_cnt = 0;
    int first = 0;
    int second = 0;
    int first_second = 0;
    // sort(moji, moji + N);
    for (int i = 0; i < N; i++) {
        // logint2(moji[i].first, moji[i].second);
        // if (contain(A[i], "AB")) {
        // AB_cnt++;
        // }
        char prev = A[i][0];
        for (int j = 1; j < A[i].length(); j++) {
            if (prev == 'A' && A[i][j] == 'B') {
                AB_cnt++;
            }
            prev = A[i][j];
        }
        if (moji[i].first == true && moji[i].second == true) {
            first_second++;
            // continue;
        }
        if (moji[i].first == true && moji[i].second == false) {
            first++;
        }
        if (moji[i].second == true && moji[i].first == false) {
            second++;
        }
    }
    // cout << "AB_cnt = " << AB_cnt << endl;
    // cout << "first  = " << first << endl;
    // cout << "second = " << second << endl;
    // cout << "fir_sec= " << first_second << endl;
    int temp_cnt = 0;
    if (first_second == 0) {
        temp_cnt = min(first, second);
    }
    if (first_second != 0) {
        if (first + second == 0) {
            temp_cnt = first_second - 1;
        } else {
            temp_cnt = first_second + min(first, second);
        }
    }
    int ans = AB_cnt + temp_cnt;
    cout << ans;

    return 0;
}
