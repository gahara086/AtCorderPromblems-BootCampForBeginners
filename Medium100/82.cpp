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
    // int A[N+1];
    long long A[N + 1];
    vector<long long> A_v;
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
        A_v.push_back(A[i]);
    };

    long long same = sum / N;
    bool same_flag = true;
    for (int i = 0; i < N; i++) {
        if (same != A[i]) {
            same_flag = false;
        }
    }
    if (same_flag) {
        long long ans = 0;
        cout << ans;
        return 0;
    }

    // long long heikin = (sum + N - 1) / N;
    long long heikin = round(((double)sum) / (double)N);
    // cout << "heikin = " << heikin << endl;

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        long long calc = (heikin - A[i]);
        calc = calc * calc;
        ans += calc;
    }
    cout << ans;

    return 0;
}
