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
    cin >> N;
    int Q;
    cin >> Q;

    int A[N + 1];
    int B[N + 1];
    for (int i = 0; i < N - 1; i++) {
        cin >> A[i];
        cin >> B[i];
    }

    int p[N + 1];
    int x[N + 1];
    for (int i = 0; i < Q; i++) {
        cin >> p[i];
        cin >> x[i];
    }

    vector<int> pos[N + 1];
    for (int i = 0; i < N - 1; i++) {
        pos[A[i]].push_back(B[i]);
        pos[B[i]].push_back(A[i]);
    }

    int ans[N + 1];
    bool flag[N + 1];
    for (int i = 0; i <= N; i++) {
        ans[i] = 0;
        flag[i] = false;
    }
    for (int k = 0; k < Q; k++) {
        ans[p[k]] += x[k];
    }

    stack<int> st;
    st.emplace(1);
    flag[1] = true;
    while (st.size() != 0) {
        int state = st.top();  // 現在の状態
        st.pop();
        for (auto next : pos[state]) {
            if (!flag[next]) {  // 未探索の時のみ行う
                flag[next] = true;
                st.emplace(next);  // 次の状態をqueueへ格納
                ans[next] += ans[state];
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}
