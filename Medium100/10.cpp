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
    int A[N + 1];
    int A_plus[N + 1];
    int A_minus[N + 1];
    int A_max = 0;
    for (int n = 1; n <= N; n++) {
        cin >> A[n];
        A_plus[n] = A[n] + 1;
        A_minus[n] = A[n] - 1;
        A_max = max(A_max, A[n]);
    }

    int A_num[A_max + 5];
    for (int n = 0; n <= A_max + 4; n++) {
        A_num[n] = 0;
    }

    for (int n = 1; n <= N; n++) {
        A_num[A[n]] += 1;
        if (A[n] - 1 >= 0) A_num[A[n] - 1] += 1;
        A_num[A[n] + 1] += 1;
    }

    int result = 0;
    for (int n = 0; n <= A_max + 4; n++) {
        result = max(result, A_num[n]);
    }
    cout << result;

    return 0;
}