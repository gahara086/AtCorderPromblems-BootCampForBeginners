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

    long long A[N + 1];
    // vector<long long> A_v;
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        // A_v.push_back(A[i]);
        sum += A[i];
    }

    long long calc = sum / 2;
    long long ans = 1000000000000000000LL;
    long long temp_ans = 1000000000000000000LL;
    long long temp_sum = 0;
    for (int i = 0; i < N - 1; i++) {
        temp_sum += A[i];
        long long temp = sum - temp_sum;
        long long temp_calc = abs(temp - temp_sum);
        // temp_ans = min(temp_ans, abs(calc - temp));
        // cout << "---------" << endl;
        // cout << "i = " << i << endl;
        // cout << "X = " << temp << endl;
        // cout << "Y = " << temp_sum << endl;

        // ans = min(ans, temp);
        ans = min(ans, temp_calc);
        // ans = min(ans, abs(sum - temp_sum * 2));
    }
    cout << ans;

    return 0;
}
