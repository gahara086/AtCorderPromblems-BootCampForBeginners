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
    if (debug_flag) cout << "arg_1 = " << n << "arg_2 = " << m << endl;
}
void logint3(int n, int m, int l) {
    if (debug_flag)
        cout << "arg_1 = " << n << "arg_2 = " << m << "arg_3 = " << l << endl;
}

void logstr1(string n) {
    if (debug_flag) cout << "arg_1 = " << n << endl;
}
void logstr2(string n, string m) {
    if (debug_flag) cout << "arg_1 = " << n << "arg_2 = " << m << endl;
}
void logstr3(string n, string m, string l) {
    if (debug_flag)
        cout << "arg_1 = " << n << "arg_2 = " << m << "arg_3 = " << l << endl;
}

int main() {
    string S;
    cin >> S;
    const long long DP_MAX = 32;
    const long long N = S.length();

    long long dp[DP_MAX][N];
    for (int i = 0; i < DP_MAX; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') {
            dp[0][i] = i + 1;
        } else if (S[i] == 'L') {
            dp[0][i] = i - 1;
        }
    }

    for (int i = 0; i < N; i++) {
        // cout << dp[0][i] << ' ';
    }
    // cout << endl;

    for (int i = 0; i < DP_MAX - 1; i++) {
        for (int j = 0; j < N; j++) {
            dp[i + 1][j] = dp[i][dp[i][j]];
        }
    }

    long long ans[N];

    for (int i = 0; i < N; i++) {
        ans[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        ans[dp[DP_MAX - 1][i]]++;
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}
