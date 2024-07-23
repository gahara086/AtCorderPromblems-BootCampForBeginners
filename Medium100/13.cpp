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
    long long N;
    cin >> N;
    long long T[N + 1], X[N + 1], Y[N + 1];
    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> X[i] >> Y[i];
    }

    long long now_T = 0;
    long long now_X = 0;
    long long now_Y = 0;

    bool ans = true;
    for (int i = 1; i <= N; i++) {
        long long distance = abs(X[i] - now_X) + abs(Y[i] - now_Y);
        long long limit_time = T[i] - now_T;

        if (distance == limit_time) {
            now_T = T[i];
            now_X = X[i];
            now_Y = Y[i];
            continue;
        }
        if (distance > limit_time) {
            // logint3(distance, limit_time, i);
            // cout << "distance < limit_time";
            // cout << endl;
            ans = false;
            break;
        }
        if ((limit_time - distance) % 2 == 1) {
            // cout << "(limit_time - distance) % 2 == 1";
            // cout << endl;
            ans = false;
            break;
        }
    }

    if (ans) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
