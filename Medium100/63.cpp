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
    int W, H, N;
    cin >> W >> H >> N;
    int W_max = W;
    int W_min = 0;
    int H_max = H;
    int H_min = 0;

    // int X[N + 2];
    // int Y[N + 2];
    // int A[N + 2];
    int X, Y, A;
    for (int i = 1; i <= N; i++) {
        // cin >> X[i] >> Y[i] >> A[i];
        cin >> X >> Y >> A;
        switch (A) {
            case 1:
                W_min = max(X, W_min);
                break;
            case 2:
                if (X <= W) {
                    W_max = min(X, W_max);
                }
                break;
            case 3:
                H_min = max(Y, H_min);
                break;
            case 4:
                if (Y <= H) {
                    H_max = min(Y, H_max);
                }
                break;
            default:
                break;
        }
    }
    int ans_H = H_max - H_min;
    int ans_W = W_max - W_min;
    int ans = ans_H * ans_W;
    if (ans <= 0 || ans_H <= 0 || ans_W <= 0) {
        ans = 0;
    }
    cout << ans;

    return 0;
}
