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
std::vector<std::vector<long long>> comb(int n, int r) {
    std::vector<std::vector<long long>> v(n + 1,
                                          std::vector<long long>(n + 1, 0));
    for (int i = 0; i < v.size(); i++) {
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for (int j = 1; j < v.size(); j++) {
        for (int k = 1; k < j; k++) {
            v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
        }
    }
    return v;
}
int main() {
    int N;
    cin >> N;

    long long A[N + 1];
    vector<long long> A_v;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A_v.push_back(A[i]);
    }

    // sort(A, A + N, greater<int>());
    sort(A, A + N);
    long long Ai = A[N - 1];
    long long Aj = A[0];
    const long long han = Ai / 2;
    long long sa = abs(han - Aj);

    for (int i = 0; i < N - 1; i++) {
        // long long sa = abs(han - Aj);
        long long temp_Aj = A[i];
        long long temp_sa = abs(han - temp_Aj);
        if (temp_sa <= sa) {
            Aj = A[i];
            sa = temp_sa;
        }
    }
    cout << Ai << ' ' << Aj;

    // long long ans = 0;
    // for (int i = 0; i < N - 1; i++) {
    //     for (int j = i + 1; j < N; j++) {
    //         // long long temp = comb(A[i], A[j]);
    //     }
    // }

    return 0;
}
