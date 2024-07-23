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
    int H;
    cin >> H;
    int W;
    cin >> W;

    int N;
    cin >> N;

    long long A[N + 1];
    vector<long long> A_v;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        A_v.push_back(A[i]);
    }

    int mass[H + 2][W + 2];
    for (int i = 0; i < H + 2; i++) {
        for (int j = 0; j < W + 2; j++) {
            mass[i][j] = 0;
        }
    }

    int cnt_h = 0;
    int cnt_w = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < A[i]; j++) {
            mass[cnt_h][cnt_w] = i;

            if (cnt_h % 2 == 0) {
                cnt_w++;
            } else {
                cnt_w--;
            }

            if (cnt_w == W) {
                cnt_h++;
                cnt_w--;
            }
            if (cnt_w == -1) {
                cnt_h++;
                cnt_w++;
            }
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << mass[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
