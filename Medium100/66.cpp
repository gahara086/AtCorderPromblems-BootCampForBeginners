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
    long long B[N + 1];
    vector<long long> B_v;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A_v.push_back(A[i]);
        cin >> B[i];
        B_v.push_back(B[i]);
    }

    long long cnt = 0;
    for (int i = N - 1; i >= 0; i--) {
        long long temp = 0;
        long long calc = 0;
        A[i] += cnt;
        if (A[i] % B[i] == 0) {
            continue;
        }

        if (A[i] > B[i]) {
            temp = A[i] % B[i];
            calc = B[i] - temp;
            cnt += calc;
        } else if (B[i] > A[i]) {
            calc = B[i] - A[i];
            cnt += calc;
        }
        // while (true) {
        //     if (A[i] % B[i] == 0) {
        //         break;
        //     }
        //     for (int j = i; j >= 0; j--) {
        //         A[j]++;
        //     }
        //     cnt++;
        // }
    }
    cout << cnt;

    return 0;
}
