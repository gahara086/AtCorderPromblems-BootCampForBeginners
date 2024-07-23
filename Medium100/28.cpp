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

double kitai(int a) {
    int sum = 0;
    for (int i = 1; i <= a; i++) {
        sum += i;
    }
    double ret = (double)sum / (double)a;

    return ret;
}

int main() {
    int N;
    cin >> N;
    int K;
    cin >> K;

    int p[N + 1];
    vector<int> A_v;
    vector<double> kitai_v;
    for (int n = 1; n <= N; n++) {
        cin >> p[n];
        A_v.push_back(p[n]);
        kitai_v.push_back(kitai(p[n]));
    }
    // sort(A_v.begin(), A_v.end(), greater<int>());
    double result = 0;
    for (int i = 0; i < K; i++) {
        result += kitai_v[i];
    }
    double temp = result;
    for (int i = K; i < N; i++) {
        // cout << kitai_v[i] << endl;
        temp += kitai_v[i];
        temp -= kitai_v[i - K];
        result = max(result, temp);
    }
    cout << fixed << setprecision(16);
    cout << result;

    // int sums[N + 1];
    // int sum = 0;
    // for (int i = 1; i <= N; i++) {
    //     sum += p[i];
    //     if (i >= K) {
    //         sums[i - K] = sum;
    //         sum = sum - p[i - K + 1];
    //     }
    // }

    // for (int i = 0; i <= N - K; i++) {
    //     cout << "sums[i] = " << sums[i] << endl;
    // }
    // int max_sum = 0;
    // for (int i = 0; i <= N - K; i++) {
    //     max_sum = max(max_sum, sums[i]);
    // }

    // double ans = 0;
    // for (int i = 0; i < K; i++) {
    //     cout << "A_v[i] = " << A_v[i] << endl;
    //     cout << "kitai(A_v[i]) = " << kitai(A_v[i]) << endl;

    //     double temp = kitai(A_v[i]);
    //     ans = ans + temp;
    // }
    // cout << fixed << setprecision(100);
    // cout << ans << endl;

    return 0;
}
