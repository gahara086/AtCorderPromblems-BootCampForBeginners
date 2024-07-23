#include <bits/stdc++.h>

#include <algorithm>
#include <cmath>  // abs() for float, and fabs()
#include <cmath>
#include <cstdlib>  // abs() for integer
#include <iostream>
#include <limits>
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

    long long K;
    cin >> K;

    double sum = 0;
    // double test = 0.4;
    // cout << test;

    for (int i = 1; i <= N; i++) {
        double temp = 1 / (double)N;
        // logint1(temp);
        long long deme = i;
        while (deme <= K - 1) {
            deme = deme * 2;
            temp = temp / 2;
        }
        // logint1(temp);
        sum += temp;
    }

    cout << setprecision(12) << sum;

    return 0;
}
