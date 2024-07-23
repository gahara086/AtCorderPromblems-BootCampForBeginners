#include <bits/stdc++.h>

#include <algorithm>
#include <cmath>    // abs() for float, and fabs()
#include <cstdlib>  // abs() for integer
#include <iostream>
#include <string>

using namespace std;

bool debug_flag = false;

void log1(int n) {
    if (debug_flag) cout << "arg_1 = " << n << endl;
}
void log2(int n, int m) {
    if (debug_flag) cout << "arg_1 = " << n << "arg_2 = " << m << endl;
}
void log3(int n, int m, int l) {
    if (debug_flag)
        cout << "arg_1 = " << n << "arg_2 = " << m << "arg_3 = " << l << endl;
}

int main() {
    string S;
    cin >> S;
    int N[S.length() + 1];

    for (int n = 0; n < S.length() + 1; n++) {
        N[n] = 0;
    }

    int now = 0;
    for (int n = 0; n < S.length(); n++) {
        if (S[n] == '<') {
            N[n + 1] = max(N[n + 1], N[n] + 1);
        }
    }
    for (int n = 0; n < S.length() + 1; n++) {
        // log1(N[n]);
    }

    for (int n = S.length(); n > 0; n--) {
        if (S[n - 1] == '>') {
            N[n - 1] = max(N[n - 1], N[n] + 1);
        }
    }

    // for (int n = 0; n < S.length(); n++) {
    // if (S[n] == '<') {
    //     N[n + 1] = max(N[n], N[n] + 1);
    // }
    // if (S[n] == '>') {
    //     N[n + 1] = min(N[n], N[n] - 1);
    // }
    // }

    for (int n = 0; n < S.length() + 1; n++) {
        log1(N[n]);
    }

    long long sum = 0;
    for (int n = 0; n < S.length() + 1; n++) {
        sum += N[n];
    }
    cout << sum;

    return 0;
}