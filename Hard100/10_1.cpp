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
    long long N;
    cin >> N;
    long long K;
    cin >> K;

    long long A[N + 1];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // sum = 0として合計値がどのタイミングで上回るのかを見つければOK
    // 尺取り法で解く
    //
    // sumは事前に計算しておく必要はない
    long long sum = 0;
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];

        long long cnt = 0;
        long long temp_sum = sum;
        while (true) {
            if (temp_sum >= K) {
                ans += N - cnt - i;
                break;
            }
            cnt++;
            temp_sum += A[i + cnt];
        }

        sum -= A[i];
    }
    cout << ans;

    return 0;
}
