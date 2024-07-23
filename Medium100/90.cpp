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
    long long Q;
    cin >> Q;

    string S;
    cin >> S;

    // int A[N+1];
    long long A[Q + 1];
    vector<long long> A_v;
    long long B[Q + 1];
    vector<long long> B_v;
    for (int i = 1; i <= Q; i++) {
        cin >> A[i];
        cin >> B[i];
        A_v.push_back(A[i]);
        B_v.push_back(B[i]);
    }

    // calc
    long long sum[N];
    for (int i = 0; i < N; i++) {
        sum[i] = 0;
    }
    char prev = S[0];
    for (int i = 1; i < N; i++) {
        if (S[i] == 'C' && prev == 'A') {
            sum[i] = sum[i - 1] + 1;
        } else {
            sum[i] = sum[i - 1];
        }
        prev = S[i];
    }

    long long ans[Q + 1];
    for (int i = 1; i <= Q; i++) {
        ans[i] = sum[B[i] - 1] - sum[A[i] - 1];
    }
    for (int i = 1; i <= Q; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
