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
    int N;
    int M;
    cin >> N;
    cin >> M;

    int P[M + 1];
    int Y[M + 1];
    // set<int> city[N + 1];
    vector<int> city[N + 1];

    // xxx
    // 二分探索を使っていて解き方はあってるけど答えの出力のさせ方で時間をとってる？
    // xxx
    // 先頭から何番目かをsetでもvectorでも取得できるのはまとめておく

    for (int i = 0; i < M; i++) {
        cin >> P[i];
        cin >> Y[i];
        city[P[i]].push_back(Y[i]);
    }
    // for (int i = 0; i < M; i++) {
    //     sort(city[P[i]].begin(), city[P[i]].end());
    // }
    for (int i = 0; i < N + 1; i++) {
        sort(city[i].begin(), city[i].end());
    }

    int pre[M + 1];
    int post[M + 1];
    string id[M + 1];
    for (int i = 0; i < M; i++) {
        pre[i] = P[i];

        auto it = lower_bound(city[P[i]].begin(), city[P[i]].end(), Y[i]);
        int cnt = distance(city[P[i]].begin(), it) + 1;

        post[i] = cnt;
    }

    for (int i = 0; i < M; i++) {
        cout << setfill('0') << right << setw(6) << to_string(pre[i]);
        cout << setfill('0') << right << setw(6) << to_string(post[i]) << endl;
    }

    return 0;
}
