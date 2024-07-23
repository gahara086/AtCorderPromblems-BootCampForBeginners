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
    // int H;
    long long H;
    cin >> H;
    // int W;
    long long W;
    cin >> W;

    string S[H + 10];
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    bool flag[H + 10][W + 10];
    long long cnt[H + 10][W + 10];
    for (int i = 0; i < H + 10; i++) {
        for (int j = 0; j < W + 10; j++) {
            flag[i][j] = false;
        }
    }
    flag[0][0] = true;
    cnt[0][0] = 0;
    cnt[H - 1][W - 1] = -1;

    queue<pair<int, int>> que;
    pair<int, int> temp = {0, 0};
    que.emplace(temp);  // sから探索する

    long long test = 0;
    while (que.size() != 0) {                // 幅優先探索
        pair<int, int> state = que.front();  // 現在の状態
        que.pop();
        test++;

        if (state.first + 1 < H) {
            if (!flag[state.first + 1][state.second] &&
                S[state.first + 1][state.second] != '#') {
                flag[state.first + 1][state.second] = true;
                cnt[state.first + 1][state.second] =
                    cnt[state.first][state.second] + 1;
                pair<int, int> next = {state.first + 1, state.second};
                // que.emplace(next);  // 次の状態をqueueへ格納
                que.push(next);  // 次の状態をqueueへ格納
                if (state.first + 1 == H - 1 && state.second == W - 1) {
                    break;
                }
            }
        }
        if (state.first - 1 >= 0) {
            if (!flag[state.first - 1][state.second] &&
                S[state.first - 1][state.second] != '#') {
                flag[state.first - 1][state.second] = true;
                cnt[state.first - 1][state.second] =
                    cnt[state.first][state.second] + 1;
                pair<int, int> next = {state.first - 1, state.second};
                que.push(next);  // 次の状態をqueueへ格納
                if (state.first - 1 == H - 1 && state.second == W - 1) {
                    break;
                }
            }
        }
        if (state.second + 1 < W) {
            if (!flag[state.first][state.second + 1] &&
                S[state.first][state.second + 1] != '#') {
                flag[state.first][state.second + 1] = true;
                cnt[state.first][state.second + 1] =
                    cnt[state.first][state.second] + 1;
                pair<int, int> next = {state.first, state.second + 1};
                que.push(next);  // 次の状態をqueueへ格納
                if (state.first == H - 1 && state.second + 1 == W - 1) {
                    break;
                }
            }
        }
        if (state.second - 1 >= 0) {
            if (!flag[state.first][state.second - 1] &&
                S[state.first][state.second - 1] != '#') {
                flag[state.first][state.second - 1] = true;
                cnt[state.first][state.second - 1] =
                    cnt[state.first][state.second] + 1;
                pair<int, int> next = {state.first, state.second - 1};
                que.push(next);  // 次の状態をqueueへ格納
                if (state.first == H - 1 && state.second - 1 == W - 1) {
                    break;
                }
            }
        }
    }
    // cout << cnt[H - 1][W - 1] << endl;
    long long cnt_s = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') {
                cnt_s++;
            }
        }
    }
    // cout << H * W << endl;
    // cout << cnt_s << endl;
    if (cnt[H - 1][W - 1] == -1) {
        cout << -1;
        return 0;
    }

    long long ans = H * W - cnt_s - cnt[H - 1][W - 1] - 1;
    cout << ans;

    return 0;
}
