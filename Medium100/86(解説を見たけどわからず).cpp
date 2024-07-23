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

    // int A[N+1];
    long long A[N + 1];

    vector<long long> A_v;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        // cout << "A[i] = " << A[i] << endl;
        A_v.push_back(A[i]);
    }

    // calc
    bool ans = true;
    long long temp = A[0] ^ A[1] ^ A[N - 1];
    if (temp == A[0]) {
    } else {
        cout << "temp = " << temp << endl;
        cout << "A[0] = " << A[0] << endl;
        ans = false;
    }

    for (int i = 1; i < N - 1; i++) {
        long long calc = A[i] ^ A[i - 1] ^ A[i + 1];
        if (calc == A[i]) {
        } else {
            cout << "calc = " << calc << endl;
            cout << "A[i] = " << A[i] << endl;
            ans = false;
        }
    }
    long long temp_last = A[N - 1] ^ A[N - 2] ^ A[0];
    if (temp_last == A[N - 1]) {
    } else {
        cout << "temp_last = " << temp_last << endl;
        cout << "A[N - 1]  = " << A[N - 1] << endl;
        ans = false;
    }

    if (ans == true) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
