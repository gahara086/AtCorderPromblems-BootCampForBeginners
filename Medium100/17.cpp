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
    long long T;
    cin >> T;

    long long A[N + 1];
    // vector<long long> A_vector;
    for (int n = 1; n <= N; n++) {
        cin >> A[n];
        // A_vector.push_back(A[n]);
    }

    long long sum = T;
    long long time = 0;
    A[0] = 0;
    for (int n = 2; n <= N; n++) {
        time = A[n];
        if (T > A[n] - A[n - 1]) {
            sum += T - (T - (A[n] - A[n - 1]));
        } else {
            sum += T;
        }
    }
    cout << sum;

    return 0;
}
