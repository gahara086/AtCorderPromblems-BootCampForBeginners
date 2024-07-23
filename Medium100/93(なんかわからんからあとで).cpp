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
    int N;
    cin >> N;
    int M;
    cin >> M;

    int k_que[11];
    int K[11][11];
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            K[i][j] = 0;
        }
    }
    for (int i = 1; i <= M; i++) {
        cin >> k_que[i];
        for (int j = 1; j <= k_que[i]; j++) {
            cin >> K[i][j];
        }
    }

    int P[11];
    for (int i = 0; i < 11; i++) {
        P[i] = 0;
    }
    for (int i = 1; i <= M; i++) {
        cin >> P[i];
    }

    // calc;
    bool flag[11];
    for (int i = 0; i < 11; i++) {
        flag[i] = false;
    }

    long long cnt = pow(2, N) - 1;
    for (int i = cnt; i >= 0; i--) {
        for (int j = 0; j <= N; j++) {
            int temp = cnt >> j;
            int bit = temp && 1;
        }
    }

    return 0;
}
