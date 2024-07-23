#include <bits/stdc++.h>

#include <algorithm>
#include <cmath>    // abs() for float, and fabs()
#include <cstdlib>  // abs() for integer
#include <iostream>
#include <string>

using namespace std;

bool debug_flag = true;

void log_1(int n) {
    if (debug_flag) cout << "arg_1 = " << n << endl;
}
void log_2(int n, int m) {
    if (debug_flag) cout << "arg_1 = " << n << "arg_2 = " << m << endl;
}
void log_3(int n, int m, int l) {
    if (debug_flag)
        cout << "arg_1 = " << n << "arg_2 = " << m << "arg_3 = " << l << endl;
}

int main() {
    string S;
    cin >> S;

    long long binary = 0;
    long long score = 0;
    long long black = 0;
    // for (int i = 0; i < S.length(); i++) {
    //     if (S.at(i) == 'B') {
    //         int temp = S.length();
    //         binary += (1 << (temp - i - 1));
    //         score += i + 1 - black;
    //         black++;
    //         // cout << "hoge";
    //         log_1(score);
    //     } else {
    //     }
    // }

    //---------------
    // cout << S.size();
    // int i = S.size();
    for (int i = S.size() - 1; i >= 0; i--) {
        if (S.at(i) == 'B') {
            int temp = S.size();
            binary += (1 << (temp - i - 1));
            // score += i - black;
            // cout << S.size() - i - 1 - black << endl;
            score += S.size() - i - 1 - black;
            black++;
            // log_1(score);
        } else {
        }
    }

    // cout << bitset<8>(binary) << endl;
    cout << score << endl;

    // int cnt = 0;
    // int target = 0;

    // while (true) {
    //     int temp = binary;
    //     while (true) {
    //         if (temp & 1) {
    //         } else {
    //             temp = temp >> 1;
    //         }
    //     }
    // }

    return 0;
}