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
    // int N;
    long long N;
    cin >> N;

    // string A[N + 1];
    string A;
    vector<string> A_v;
    long long cnt_M = 0;
    long long cnt_A = 0;
    long long cnt_R = 0;
    long long cnt_C = 0;
    long long cnt_H = 0;
    long long cnt[5];
    for (int i = 0; i < 5; i++) {
        cnt[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        // cin >> A[i];
        // A_v.push_back(A[i]);
        cin >> A;
        if (A[0] == 'M') {
            cnt_M++;
            cnt[0]++;
        }
        if (A[0] == 'A') {
            cnt_A++;
            cnt[1]++;
        }
        if (A[0] == 'R') {
            cnt_R++;
            cnt[2]++;
        }
        if (A[0] == 'C') {
            cnt_C++;
            cnt[3]++;
        }
        if (A[0] == 'H') {
            cnt_H++;
            cnt[4]++;
        }
    }

    long long ans = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            for (int k = j + 1; k < 5; k++) {
                long long temp = cnt[i] * cnt[j] * cnt[k];
                ans += temp;
            }
        }
    }
    cout << ans;

    // for (int i = 1; i <= N; i++) {
    //     cin >> A[i];
    //     A_v.push_back(A[i]);
    // }

    return 0;
}
