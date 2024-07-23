#include <bits/stdc++.h>

#include <algorithm>
#include <cmath>    // abs() for float, and fabs()
#include <cstdlib>  // abs() for integer
#include <iostream>
#include <string>

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

    int A[N + 1];

    long long rate[9];
    for (int n = 1; n <= N; n++) {
        cin >> A[n];
    }

    for (int i = 0; i < 9; i++) {
        rate[i] = 0;
    }

    for (int n = 1; n <= N; n++) {
        if (1 <= A[n] && A[n] <= 399) {
            rate[0]++;
        } else if (400 <= A[n] && A[n] <= 799) {
            rate[1]++;
        } else if (800 <= A[n] && A[n] <= 1199) {
            rate[2]++;
        } else if (1200 <= A[n] && A[n] <= 1599) {
            rate[3]++;
        } else if (1600 <= A[n] && A[n] <= 1999) {
            rate[4]++;
        } else if (2000 <= A[n] && A[n] <= 2399) {
            rate[5]++;
        } else if (2400 <= A[n] && A[n] <= 2799) {
            rate[6]++;
        } else if (2800 <= A[n] && A[n] <= 3199) {
            rate[7]++;
        } else {
            rate[8]++;
        }
    }

    long long min_case = 0;
    for (int i = 0; i < 8; i++) {
        if (rate[i] != 0) min_case++;
    }
    bool false_flag = false;
    if (min_case == 0) {
        false_flag = true;
        min_case = 1;
        // min_case = 0;
        // min_case = rate[8];
    }

    long long max_case = min_case + rate[8];
    // max_case = (max_case >= 8) ? 8 : max_case;
    if (false_flag) {
        // max_case = rate[8] >= 8 ? 8 : rate[8];
        max_case = rate[8];
    }

    cout << min_case << ' ' << max_case;

    // cout << min_rate << ' ' << max_rate;

    return 0;
}