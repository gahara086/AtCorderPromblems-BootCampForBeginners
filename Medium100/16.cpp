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

    int S[N + 1];
    for (int n = 1; n <= N; n++) {
        cin >> S[n];
    }

    // 点数の最大値1000までループさせるのでOK
    bool dp[100001][N + 1];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= 100000; j++) {
            dp[j][i] = false;
        }
    }
    dp[0][0] = true;
    S[0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 100000; j++) {
            if (dp[j][i - 1] == true) {
                // logint2(j, i);
                // logint1(S[i]);
                dp[j][i] = true;
                dp[S[i]][i] = true;
                dp[j + S[i]][i] = true;
            }
        }
    }

    int result = 0;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= 100000; j++) {
            if (j % 10 == 0) {
                continue;
            }
            if (dp[j][i] == true) {
                // cout << "hoge";
                result = j;
            }
        }
    }
    cout << result;
    return 0;
}
