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
    long long N;
    cin >> N;
    long long D[N + 1];
    vector<long long> D_v;
    for (int i = 1; i <= N; i++) {
        cin >> D[i];
        D_v.push_back(D[i]);
    }
    sort(D_v.begin(), D_v.end());

    long long M;
    cin >> M;
    long long T[M + 1];
    vector<long long> T_v;
    for (int i = 1; i <= M; i++) {
        cin >> T[i];
        T_v.push_back(T[i]);
    }
    sort(T_v.begin(), T_v.end());

    bool ans = true;
    for (long long i = 0; i < M; i++) {
        auto iter = lower_bound(D_v.begin(), D_v.end(), T_v[i]);
        if (*iter != T_v[i]) {
            ans = false;
            break;
        }
        *iter = -1;
    }

    if (ans) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
