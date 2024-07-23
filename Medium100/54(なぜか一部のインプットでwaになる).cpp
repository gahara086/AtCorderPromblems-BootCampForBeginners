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
    int N;
    cin >> N;
    int C;
    cin >> C;
    int K;
    cin >> K;

    // int A[N+1];
    int A[100000];
    vector<int> A_v;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A_v.push_back(A[i]);
    }

    sort(A, A + N);

    int time = 0;
    int time_hate = 0;
    int cnt_hito = 1;
    int cnt_bus = 1;
    // for (int i = 0; i < N; i++) {
    // logint1(A[i]);
    // }
    for (int i = 0; i < N; i++) {
        // cnt_hito++;
        int time_calc = time_hate + A[i] - time;
        // cout << "time = " << time << endl;
        // cout << "A[i] = " << A[i] << endl;
        // cout << "time_hate = " << time_hate << endl;
        // cout << "time_calc = " << time_calc << endl;
        // cout << "cnt_hito  = " << cnt_hito << endl;
        if (time_calc > K || cnt_hito > C) {
            // cout << "time_calc >= K || cnt_hito > C" << endl;
            // cout << "time_calc = " << time_calc << endl;
            time_hate = 0;
            cnt_hito = 1;
            // if (i != N - 1) {B
            cnt_bus++;
            time = A[i];
            // }
        }
        cnt_hito++;
        time_calc = time_hate + A[i] - time;

        time_hate = time_hate + A[i] - time;
        time = A[i];
    }
    cout << cnt_bus;

    return 0;
}