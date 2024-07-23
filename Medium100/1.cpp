#include <bits/stdc++.h>

#include <algorithm>
#include <cmath>    // abs() for float, and fabs()
#include <cstdlib>  // abs() for integer
#include <iostream>
#include <string>

using namespace std;

// #define log(s, n) cout << s << " = " << n << endl;
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
    long long N;
    cin >> N;

    long long A[N + 1];
    // long long A_flag[N + 1];
    for (int n = 1; n <= N; n++) {
        cin >> A[n];
        // A_flag[n] = false;
    }

    int lihgt = 1;
    int cnt = 0;

    while (true) {
        if (lihgt == 2) {
            break;
        }
        cnt++;
        lihgt = A[lihgt];
        if (cnt > 100000) {
            cnt = -1;
            break;
        }
    }
    cout << cnt;

    return 0;
}