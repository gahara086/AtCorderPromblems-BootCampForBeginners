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
    long long A, B, C;
    cin >> A >> B >> C;

    long long calc_A = A * A;
    long long calc_B = B * B;
    long long calc_C = C * C;
    // long long pow_ABC = pow(C - A - B, 2);
    long long D = C - A - B;
    // long long pow_ABC = (C - A - B) * (C - A - B);
    long long AB4 = 4 * A * B;
    // logint2(pow_ABC, AB4);
    if (D > 0 && AB4 < D * D) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    // long double calc_A = sqrt(A);
    // long double calc_B = sqrt(B);
    // long double calc_C = sqrt(C);
    // if (calc_C > calc_A + calc_B) {
    //     cout << "Yes";
    // } else {
    //     cout << "No";
    // }
    return 0;
}
