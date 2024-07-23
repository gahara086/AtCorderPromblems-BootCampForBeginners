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
    // int M;
    long long M;
    cin >> M;

    long long A[M + 1];
    vector<long long> A_v;
    long long B[M + 1];
    vector<long long> B_v;
    for (int i = 1; i <= M; i++) {
        cin >> A[i];
        cin >> B[i];
        A_v.push_back(A[i]);
        B_v.push_back(B[i]);
    }

    long long hako[N + 1];
    bool flag[N + 1];
    bool kako[N + 1];
    for (int i = 0; i <= N; i++) {
        hako[i] = 1;
        flag[i] = false;
        kako[i] = false;
    }
    flag[1] = true;
    kako[1] = true;

    // for (int i = 1; i <= N; i++) {
    //     cout << "i = " << i << endl;
    //     cout << "hako[i] = " << hako[i] << endl;
    // }

    for (int i = 1; i <= M; i++) {
        if (flag[A[i]] == true && hako[A[i]] > 0) {
            flag[B[i]] = true;
            kako[B[i]] = true;
            hako[A[i]]--;
            hako[B[i]]++;
            if (hako[A[i]] == 0) {
                flag[A[i]] = false;
                kako[A[i]] = false;
            }
        } else if (flag[A[i]] == false) {
            hako[A[i]]--;
            hako[B[i]]++;
        }
    }

    for (int i = 1; i <= N; i++) {
        // cout << "i = " << i << endl;
        // cout << "hako[i] = " << hako[i] << endl;
        // cout << "kako[i] = " << kako[i] << endl;
        if (hako[i] == 0) {
            flag[i] = false;
        }
        if (hako[i] > 0 && kako[i] == true) {
            flag[i] = true;
        }
    }

    long long cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (flag[i] == true) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}
